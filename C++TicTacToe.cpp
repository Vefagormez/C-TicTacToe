#include<iostream>
#include<string>
#include<time.h>
// TÝC TAC TOE 
using namespace std;
// burada tahtayi bosluk ile dolduracagiz  
char board[3][3] = { {' ',' ',' '},{' ',' ',' '},{' ',' ',' '} };
char player1 = 'X', player2 = 'O';
void show();// gosterme fonksiyonu 
bool checkWinner(char playerSymbol);// kontrol eden fonksiyon 
int row, column,currentPlayer=1;
void player_turn();
int main() {
	
	int moves = 0;
	do
	{
		show();
		player_turn();
		// bu oyuncu sýrasý degistirmek icin yazýlmýþ kod 
		currentPlayer = (currentPlayer % 2) + 1;
		moves++;
		if (checkWinner(player1))
		{
			show();
			cout << "Oyunucu 1 kazandi " << endl;
			break;
		}
		else if (checkWinner(player2)) {
			show();
			cout << "Oyuncu 2 kazandi " << endl;
			break;
		}
		else if (moves == 9) {
			show();
			cout << "Berabere " << endl;
			break;
		}




	} while (true);

	
	return 0;
}
// kazananý kontrol etmek icin yapýlýr 
bool checkWinner(char playerSymbol) {
	// dikey kazanmalar  icin (for vertical wins )
	for (int i = 0; i < 3; i++) {
		if (board[i][0] == playerSymbol && board[i][1] == playerSymbol && board[i][2] == playerSymbol)
			return true;
	}
	// yatay kazanmalar için (for horizontal gains ) 
	for (int j = 0; j < 3; j++) {
		if (board[0][j] == playerSymbol && board[1][j] == playerSymbol && board[2][j] == playerSymbol)
			return true;
	}
	// capraz kazanmalar icin (for cross winnings )
	if (board[0][0] == playerSymbol && board[1][1] == playerSymbol && board[2][2] == playerSymbol)
		return true;
	else if (board[0][2] == playerSymbol && board[1][1] == playerSymbol && board[2][0] == playerSymbol)
		return true;
	return false;
}
void show() {

	cout << "__________________________" << endl;
	cout << "|\t" << board[0][0] << "|\t" << board[0][1] << "|\t" << board[0][2] << "|\t" << endl;

	cout << "|________|_______|_______|" << endl;
	cout << "|\t" << board[1][0] << "|\t" << board[1][1] << "|\t" << board[1][2] << "|\t" << endl;
	cout << "|________|_______|_______|" << endl;
	cout << "|\t" << board[2][0] << "|\t" << board[2][1] << "|\t" << board[2][2] << "|\t" << endl;
	cout << "|________|_______|_______|" << endl;

}
void player_turn() {
	int secim;
	cout << "lutfen nereye gireceginiz giriniz " << endl;
	cin >> secim;

	switch (secim) {
	case 1:
		row = 0, column = 0;
		break;
	case 2: 
		row = 0, column = 1;
		break;
	case 3:
		row = 0, column = 2;
	case 4: 
		row = 1, column = 0;
		break;
	case 5:
		row = 1, column = 1;
		break;
	case 6: 
		row = 1, column = 2;
		break;
	case 7:
		row = 2, column = 0;
		break;
	case 8:
		row = 2, column = 1;
		break;
	case 9:
		row = 2, column = 2;
		break;
		default:
			cout << "lutfen 1-9 arasinda deger giriniz " << endl;
			player_turn();
			break;
	}
	if (board[row][column] == ' ') {
		if (currentPlayer == 1)
			board[row][column] = player1;
		else
			board[row][column] = player2;
	}
	else {
		cout << "Secilen pozisyon dolu Lutfen baska bir pozisyona yazýnýz " << endl;
		player_turn();

	}

}