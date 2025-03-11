

#ifndef __funciones__
#define __funciones__

#include<fstream>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <random>
using namespace std;


/*direcciones*/

vector <pair<int, int> > direcciones = { {0,1}, {0,-1}, {-1,0}, {1,0} };


// Retorna cierto si estoy dentro del límite del mapa, en caso contrario, retorna falso
bool limitado(vector < vector<char>>& T, int i, int j) {
	return i >= 0 and j >= 0 and i < int(T.size()) and j < int(T[0].size());
}

/*si encuentro el elemento buscado devolver lo encontre
		sino va a devolver no encontre*/

bool algoritmo_bfs(vector <vector<char>> R, int i, int j, vector<pair<int, int>>& camino) {

	/*condicion de para de la llamada recursiva*/

	if (R[i][j] == 't') {
		camino.push_back({ i,j });
		return true;
	}
	if (R[i][j] == 'X') {

		return false;
	}

	/*condicion de visitado*/

	R[i][j] = 'X';
	camino.push_back({ i,j });

	/*direccionamiento*/


	// Moverme en el mapa

	for (auto& d : direcciones) {

		int adj_i = i + d.first;
		int adj_j = j + d.second;


		// (adj_i,adj_j) nueva posicion casilla
		// cout << "Y: " << adj_i << " " << " X: " << adj_j << "\n";
		if (limitado(R, adj_i, adj_j) and algoritmo_bfs(R, adj_i, adj_j, camino)) {


			return true;
		}

	}
	camino.pop_back();
	return false;	// No he sido capaz de llegar a ningún tesoro
}

vector<vector<char>> automap_generation(int v, int a) {
	vector<char> characters = { 't','X','.','a','e','i','o','u'};
	vector <vector<char>> map(v, vector<char>(a));

	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> dist(0, characters.size() - 1);

	for (int i = 0; i < v; i++)
	{
		for (int j = 0; j < a; j++) {
			map[i][j] = characters[dist(gen)];
		}
	}

	return map;
}

void print_map(vector<vector<char>> R) {
	for(const auto& row : R) {
		for(const auto& cell : row) {
			cout << cell << " ";
		}
		cout << '\n';
	}
}

void save_results(int x, int y, bool encontrado, vector<pair<int, int>> camino) {
	ofstream archivo("resultados.txt", ios::app); // Modo append para no sobrescribir
	if (!archivo) {
		cerr << "Error al abrir el archivo.\n";
		return;
	}

	archivo << "Posición inicial: (" << x << ", " << y << ")\n";
	if (encontrado) {
		archivo << "Llegó al tesoro. Recorrido:\n";
		for (auto& paso : camino) {
			archivo << "(" << paso.first + 1 << ", " << paso.second + 1 << ") -> ";
		}
		archivo << "TESORO\n";
	}
	else {
		archivo << "No llegó al tesoro.\n";
	}
	archivo << "----------------------\n";

	archivo.close();  
}

void grafo_dfs() {
	/*1. Un Grafo tiene vertices y aristas*/

	int v; /*cantidad de vertices*/
	int a; /*cantidad de aristas*/

	cout << "Ingrese el numero de filas y columnas: ";
	cin >> v >> a;

	/*2. Vamos a definir el grafo*/

	vector <vector<char>> R;

	char option;
	cout << "Desea generar un mapa automaticamente? (s/n): ";
	cin >> option;

	/*3. vamos a llenar el grafo o la cuadricula*/

	if (option == 's')
	{
		R = automap_generation(v, a);
		print_map(R);
	}
	else {
		cout << "Por favor ingrese el mapa: \n";
		R = vector<vector<char>>(v, vector<char>(a));

		for (int i = 0; i < v; i++) {

			for (int j = 0; j < a; j++) {

				cin >> R[i][j];

			}
		}
	}


	int r;	// fila inicial en que me encuentro
	int c;	// columna inicial en que me encuentro
	cout << "Ingrese la fila y columna inicial: \n";
	cin >> r >> c;

	vector<pair<int, int>> camino;
	bool respuesta = algoritmo_bfs(R, r - 1, c - 1, camino);	// retornara true si puedo llegar a un tesoro desde (r,c)
	// en caso contrario, retornara false

	if (respuesta) cout << "Has llegado al tesoro!";
	else cout << "No has llegado al tesoro!";
	cout << endl;	// salto de linea
	save_results(r, c, respuesta, camino);
	
}

#endif // !__funciones__
