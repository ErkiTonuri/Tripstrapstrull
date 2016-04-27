#include <iostream>
using namespace std;

// loob mängulaua ja nummerdab kõik kohad ära
char matrix[3][3] = { '1', '2', '3', '4', '5', '6', '7', '8', '9' };
// loob mängija
char player = 'X';

void Draw()
// Joonistab mängulaua konsooli
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
}

void Input()
{
	// inimene sisestab numbri kuhu tahab käia
	int a;
	cout << "Vali millise kohta tahad käia: ";
	cin >> a;

	if (a == 1)
		matrix[0][0] = player;
	else if (a == 2)
		matrix[0][1] = player;
	else if (a == 3)
		matrix[0][2] = player;
	else if (a == 4)
		matrix[1][0] = player;
	else if (a == 5)
		matrix[1][1] = player;
	else if (a == 6)
		matrix[1][2] = player;
	else if (a == 7)
		matrix[2][0] = player;
	else if (a == 8)
		matrix[2][1] = player;
	else if (a == 9)
		matrix[2][2] = player;
}

void TogglePlayer()
{
	// vahetab mängia ära peale igat käiku
	if (player == 'X')
		player = 'O';
	else
		player = 'X';
}

char Win()
{
	// kontrollib kas 1 mängija võibab 
	// kontrollin ridu
	if (matrix[0][0] == 'X' && matrix[0][1] == 'X' && matrix[0][2] == 'X')
		return 'X';
	if (matrix[1][0] == 'X' && matrix[1][1] == 'X' && matrix[1][2] == 'X')
		return 'X';
	if (matrix[2][0] == 'X' && matrix[2][1] == 'X' && matrix[2][2] == 'X')
		return 'X';

	//kontrollib veerge
	if (matrix[0][0] == 'X' && matrix[1][0] == 'X' && matrix[2][0] == 'X')
		return 'X';
	if (matrix[0][1] == 'X' && matrix[1][1] == 'X' && matrix[2][1] == 'X')
		return 'X';
	if (matrix[0][2] == 'X' && matrix[1][2] == 'X' && matrix[2][2] == 'X')
		return 'X';

	//kontrollib diagonaale
	if (matrix[0][0] == 'X' && matrix[1][1] == 'X' && matrix[2][2] == 'X')
		return 'X';
	if (matrix[2][0] == 'X' && matrix[1][1] == 'X' && matrix[0][2] == 'X')
		return 'X';

	// kontrollib kas teine mängija võibab
	// vahetas ümber Notepad++, et kiiremini teha

	// kontrollin ridu
	if (matrix[0][0] == 'O' && matrix[0][1] == 'O' && matrix[0][2] == 'O')
		return 'O';
	if (matrix[1][0] == 'O' && matrix[1][1] == 'O' && matrix[1][2] == 'O')
		return 'O';
	if (matrix[2][0] == 'O' && matrix[2][1] == 'O' && matrix[2][2] == 'O')
		return 'O';

	//kontrollib veerge
	if (matrix[0][0] == 'O' && matrix[1][0] == 'O' && matrix[2][0] == 'O')
		return 'O';
	if (matrix[0][1] == 'O' && matrix[1][1] == 'O' && matrix[2][1] == 'O')
		return 'O';
	if (matrix[0][2] == 'O' && matrix[1][2] == 'O' && matrix[2][2] == 'O')
		return 'O';

	//kontrollib diagonaale
	if (matrix[0][0] == 'O' && matrix[1][1] == 'O' && matrix[2][2] == 'O')
		return 'O';
	if (matrix[2][0] == 'O' && matrix[1][1] == 'O' && matrix[0][2] == 'O')
		return 'O';

	//tagastab midagi muidu paneb programm metsa
	return '/';
}

int main()
{
	// kutsub joonistamise välja
	Draw();
	// loob lõpmatu korduse
	while (1)
	{
		Input();
		Draw();
		if (Win() == 'X')
		{
			cout << "1. mängija võitis" << endl;
			break;
		}
		else if (Win() == 'Y')
		{
			cout << "2. mängija võitis" << endl;
			break;
		}
		TogglePlayer();
	}
	// süsteemi paus enne kui paneb programmi kinni
	system("pause");
	// sulgeb programmi
	return 0;
}