

#ifndef __funciones__
#define __funciones__

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

bool algoritmo_bfs(vector <vector<char>> R, int i, int j) {

	/*condicion de para de la llamada recursiva*/

	if (R[i][j] == 't') {
		return true;
	}
	if (R[i][j] == 'X') {

		return false;
	}

	/*condicion de visitado*/

	R[i][j] = 'X';

	/*direccionamiento*/

	R[i][j] = 'X';	// VISITADO

	// Moverme en el mapa

	for (auto& d : direcciones) {

		int adj_i = i + d.first;
		int adj_j = j + d.second;


		// (adj_i,adj_j) nueva posicion casilla
		// cout << "Y: " << adj_i << " " << " X: " << adj_j << "\n";
		if (limitado(R, adj_i, adj_j) and algoritmo_bfs(R, adj_i, adj_j)) {


			return true;
		}

	}

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


	bool respuesta = algoritmo_bfs(R, r - 1, c - 1);	// retornara true si puedo llegar a un tesoro desde (r,c)
	// en caso contrario, retornara false

	if (respuesta) cout << "yes";
	else cout << "no";
	cout << endl;	// salto de linea

	
}

#endif // !__funciones__
