#include <iostream>
#include <ctime>
#include <cstdlib>
#include<conio.h>
using namespace std;

const int rows = 10 ;
const int elements = 10 ;
int Matrix[rows][elements];     // PC ZONE
int MyArea[rows][elements];     // MY ZONE

int last_Ship = -1;
int last_Ship_id = 0;

int last_my_Ship = -1;
int last_my_Ship_id = 0;


struct SHIPS
{
    int Boxes;          // The number of boxes you start with
    int BoxesLeft;    // Number of houses left
    int coordinates[10][2];   // coordinates occupied by the ship
};
void Play_Game()
{
	system("cls");
    for(int i=0;i<10;i++)
    cout<<endl;
    for(int i=0;i<30;i++)
    cout<<" ";
	cout<<"Select the difficulty level:\n";
	for(int i=0;i<30;i++)
    cout<<" ";
	cout<<"1: Easy\n";
	for(int i=0;i<30;i++)
	cout<<" ";
	cout<<"2: Medium\n";
    for(int i=0;i<30;i++)
    cout<<" ";
    cout<<"3: Hard\n";
    getch();
}
void Rules()
{
	system("cls");
        cout<<"Get ready for the war!\n";
        cout<<"1. You have to destroy your opponent's war ships before he destroys yours.\n";
        cout<<"2. The battlefield is of 10x10 grid size in which you place your ships\n";
        cout<<"3. You can place your ships by entering its orientation, i.e horizontal or vertical. For horizontal orientation, type 'h' in the orientation option and type 'v' for vertical\n";
        cout<<"4. and its x y coordinates(both separated by a space) where x is the row number and y is the column number\n";
        cout<<"4. You have a fleet of 4 battle ships: Aircraft Carrier (5 units long), Battleship (4 units long), Destroyer (3 units long) and Corvette (2 units long)\n";
        cout<<"5. After placing your ships, you can attack the enemy area. To attack a area, enter its x y coordinate (separated by a space)\n";
        cout<<"6. Attack hit to the enemy ship is denoted by a 'H' and you get an extra turn\n";
        cout<<"7. Attack miss is denoted by a '*' and your turn ends\n\n";
        cout<<"Press ENTER to continue!";
        getch();
}
void Credits()
{
	cout<<"Made by Sufyan Malik and M. Usman Aziz\n\n";
	cout<<"Press ENTER to continue!";
	getch();
}
void Main_Menu()
{
	int ch;
	system("cls");
    for(int i=0;i<10;i++)
    cout<<endl;
    for(int i=0;i<30;i++)
    cout<<" ";
	cout<<"1: Levels\n";
	for(int i=0;i<30;i++)
    cout<<" ";
	cout<<"2: Rules\n";
	for(int i=0;i<30;i++)
	cout<<" ";
	cout<<"3: Credits\n";
    for(int i=0;i<30;i++)
    cout<<" ";
    cout<<"4: Quit\n";
    for(int i=0;i<30;i++)
    cout<<" ";
    cout<<"\nEnter Choice: ";
    getch();
	
	
	cin>>ch;

	if(ch==1)
	{
		Play_Game();
	}
	else if(ch==2)
	{
		Rules();
		Main_Menu();
	}
	else if(ch==3)
	{
		Credits();
		Main_Menu();
	}
	else if(ch==4)
	{
		exit(0);
	}
}

SHIPS Zone[10];
SHIPS ZonePC[10];

void Add_Zone(int Area, int dim, int coords[][2])
{
    Zone[Area].Boxes = dim;
    Zone[Area].BoxesLeft = dim;
    int i;
    for(i = 0; i < dim; i++)
	{
        Zone[Area].coordinates[i][0] = coords[i][0];
        Zone[Area].coordinates[i][1] = coords[i][1];
        MyArea[coords[i][0]][coords[i][1]] = Area;
    }
}

void Add_PC_Zone(int Area, int dim, int coords[][2])
{
    ZonePC[Area].Boxes = dim;
    ZonePC[Area].BoxesLeft = dim;
    int i;
    for(i = 0; i < dim; i++)
	{
        ZonePC[Area].coordinates[i][0] = coords[i][0];
        ZonePC[Area].coordinates[i][1] = coords[i][1];
        Matrix[coords[i][0]][coords[i][1]] = Area;
    }
}

int getRand0or1()
{
    return rand() % 2;
}

int getRand0or3()
{
    return rand() % 4;
}

int getCoordX()
{
    return rand() % rows;
}

int getCoordY()
{
    return rand() % elements;
}

void ZoneRandom()
{
    /* To construct random Ship 1 */
    int x = getCoordX();
    int y = getCoordY();
    int Ship_1[1][2] = {{x, y}};
    Add_Zone(1, 1, Ship_1);

    /* To construct random Ship 2 */
    int idea = getRand0or1();
    do{
        do{
            x = getCoordX();
            y = getCoordY();
        }
		while((idea == 1 && y+1 > 9) || (idea == 0 && x+1 > 9));
    }
	while(MyArea[x][y] > 0 || ((idea == 1 && MyArea[x][y+1] > 0) ||(idea == 0 && MyArea[x + 1][y] > 0)));
	
    int Ship_2[2][2];
    if(idea == 1)
	{
        Ship_2[0][0] = x;
        Ship_2[0][1] = y;
        Ship_2[1][0] = x;
        Ship_2[1][1] = y + 1;
    }
	else
	{
        Ship_2[0][0] = x;
        Ship_2[0][1] = y;
        Ship_2[1][0] = x + 1;
        Ship_2[1][1] = y;
    }
    Add_Zone(2, 2, Ship_2);

    /* To construct random Ship 2 */
    idea = getRand0or1();
    do{
        do{
            x = getCoordX();
            y = getCoordY();
        }
		while((idea == 1 && (y+1 > 9 || y+2 > 9)) || (idea == 0 && (x+1 > 9 || x+2 > 9)));
    }
	while(MyArea[x][y] > 0 ||((idea == 1 && (MyArea[x][y+1] > 0 || MyArea[x][y+2] > 0)) ||(idea == 0 && (MyArea[x + 1][y] > 0 || MyArea[x + 2][y] > 0))));
    
	int Ship_3[3][2];
    if(idea == 1)
	{
        Ship_3[0][0] = x;
        Ship_3[0][1] = y;
        Ship_3[1][0] = x;
        Ship_3[1][1] = y + 1;
        Ship_3[2][0] = x;
        Ship_3[2][1] = y + 2;
    }
	else
	{
        Ship_3[0][0] = x;
        Ship_3[0][1] = y;
        Ship_3[1][0] = x + 1;
        Ship_3[1][1] = y;
        Ship_3[2][0] = x + 2;
        Ship_3[2][1] = y;
    }
    Add_Zone(3, 3, Ship_3);

    /* To construct random Ship 4 */
    idea = getRand0or1();
    do{
        do{
            x = getCoordX();
            y = getCoordY();
        }
		while((idea == 1 && (y+1 > 9 || y+2 > 9 || y+3 > 9)) || (idea == 0 && (x+1 > 9 || x+2 > 9 || x+3 > 9)));
    }
	while(MyArea[x][y] > 0 ||((idea == 1 && (MyArea[x][y+1] > 0 || MyArea[x][y+2] > 0 || MyArea[x][y+3] > 0)) ||(idea == 0 && (MyArea[x + 1][y] > 0 || MyArea[x + 2][y] > 0 || MyArea[x + 3][y] > 0))));
    int Ship_4[4][2];
    if(idea == 1)
	{
        Ship_4[0][0] = x;
        Ship_4[0][1] = y;
        Ship_4[1][0] = x;
        Ship_4[1][1] = y + 1;
        Ship_4[2][0] = x;
        Ship_4[2][1] = y + 2;
        Ship_4[3][0] = x;
        Ship_4[3][1] = y + 3;
    }
	else
	{
        Ship_4[0][0] = x;
        Ship_4[0][1] = y;
        Ship_4[1][0] = x + 1;
        Ship_4[1][1] = y;
        Ship_4[2][0] = x + 2;
        Ship_4[2][1] = y;
        Ship_4[3][0] = x + 3;
        Ship_4[3][1] = y;
    }
    Add_Zone(4, 4, Ship_4);

    /* To construct random Ship 5 */
    idea = getRand0or1();
    do{
        do{
            x = getCoordX();
            y = getCoordY();
        }
		while((idea == 1 && (y+1 > 9 || y+2 > 9 || y+3 > 9 || y+4 > 9)) || (idea == 0 && (x+1 > 9 || x+2 > 9 || x+3 > 9 || x+4 > 9)));
    }
	while(MyArea[x][y] > 0 ||((idea == 1 && (MyArea[x][y+1] > 0 || MyArea[x][y+2] > 0 || MyArea[x][y+3] > 0 || MyArea[x][y+4] > 0)) ||(idea == 0 && (MyArea[x + 1][y] > 0 || MyArea[x + 2][y] > 0 || MyArea[x + 3][y] > 0 || MyArea[x + 4][y] > 0))));
    
	int Ship_5[3][2];
    if(idea == 1)
	{
        Ship_5[0][0] = x;
        Ship_5[0][1] = y;
        Ship_5[1][0] = x;
        Ship_5[1][1] = y + 1;
        Ship_5[2][0] = x;
        Ship_5[2][1] = y + 2;
        Ship_5[3][0] = x;
        Ship_5[3][1] = y + 3;
        Ship_5[4][0] = x;
        Ship_5[4][1] = y + 4;
    }
	else
	{
        Ship_5[0][0] = x;
        Ship_5[0][1] = y;
        Ship_5[1][0] = x + 1;
        Ship_5[1][1] = y;
        Ship_5[2][0] = x + 2;
        Ship_5[2][1] = y;
        Ship_5[3][0] = x + 3;
        Ship_5[3][1] = y;
        Ship_5[4][0] = x + 4;
        Ship_5[4][1] = y;
    }
    Add_Zone(5, 5, Ship_5);
}

void ZonaPCRandom()
{
    /* To construct random Ship 1 */
    int x = getCoordX();
    int y = getCoordY();
    int Ship_1[1][2] = {{x, y}};
    Add_PC_Zone(1, 1, Ship_1);

    /* To construct random Ship 2 */
    int idea = getRand0or1();
    do{
        do{
            x = getCoordX();
            y = getCoordY();
        }
		while((idea == 1 && y+1 > 9) || (idea == 0 && x+1 > 9));
    }
	while(Matrix[x][y] > 0 ||((idea == 1 && Matrix[x][y+1] > 0) ||(idea == 0 && Matrix[x + 1][y] > 0)));
	
    int Ship_2[2][2];
    if(idea == 1){
        Ship_2[0][0] = x;
        Ship_2[0][1] = y;
        Ship_2[1][0] = x;
        Ship_2[1][1] = y + 1;
    }else{
        Ship_2[0][0] = x;
        Ship_2[0][1] = y;
        Ship_2[1][0] = x + 1;
        Ship_2[1][1] = y;
    }
    Add_PC_Zone(2, 2, Ship_2);

    /*To construct random Ship 2 */
    idea = getRand0or1();
    do{
        do{
            x = getCoordX();
            y = getCoordY();
        }while((idea == 1 && (y+1 > 9 || y+2 > 9)) || (idea == 0 && (x+1 > 9 || x+2 > 9)));
    }
	while(Matrix[x][y] > 0 ||((idea == 1 && (Matrix[x][y+1] > 0 || Matrix[x][y+2] > 0)) ||(idea == 0 && (Matrix[x + 1][y] > 0 || Matrix[x + 2][y] > 0))));
    
	int Ship_3[3][2];
    if(idea == 1)
	{
        Ship_3[0][0] = x;
        Ship_3[0][1] = y;
        Ship_3[1][0] = x;
        Ship_3[1][1] = y + 1;
        Ship_3[2][0] = x;
        Ship_3[2][1] = y + 2;
    }
	else
	{
        Ship_3[0][0] = x;
        Ship_3[0][1] = y;
        Ship_3[1][0] = x + 1;
        Ship_3[1][1] = y;
        Ship_3[2][0] = x + 2;
        Ship_3[2][1] = y;
    }
    Add_PC_Zone(3, 3, Ship_3);

    /* To construct random Ship 4 */
    idea = getRand0or1();
    do{
        do{
            x = getCoordX();
            y = getCoordY();
        }while((idea == 1 && (y+1 > 9 || y+2 > 9 || y+3 > 9)) || (idea == 0 && (x+1 > 9 || x+2 > 9 || x+3 > 9)));
    }
	while(Matrix[x][y] > 0 ||((idea == 1 && (Matrix[x][y+1] > 0 || Matrix[x][y+2] > 0 || Matrix[x][y+3] > 0)) ||(idea == 0 && (Matrix[x + 1][y] > 0 || Matrix[x + 2][y] > 0 || Matrix[x + 3][y] > 0))));
    
	int Ship_4[4][2];
    if(idea == 1)
	{
        Ship_4[0][0] = x;
        Ship_4[0][1] = y;
        Ship_4[1][0] = x;
        Ship_4[1][1] = y + 1;
        Ship_4[2][0] = x;
        Ship_4[2][1] = y + 2;
        Ship_4[3][0] = x;
        Ship_4[3][1] = y + 3;
    }
	else
	{
        Ship_4[0][0] = x;
        Ship_4[0][1] = y;
        Ship_4[1][0] = x + 1;
        Ship_4[1][1] = y;
        Ship_4[2][0] = x + 2;
        Ship_4[2][1] = y;
        Ship_4[3][0] = x + 3;
        Ship_4[3][1] = y;
    }
    Add_PC_Zone(4, 4, Ship_4);

    /* To construct random Ship 5 */
    idea = getRand0or1();
    do{
        do{
            x = getCoordX();
            y = getCoordY();
        }while((idea == 1 && (y+1 > 9 || y+2 > 9 || y+3 > 9 || y+4 > 9)) || (idea == 0 && (x+1 > 9 || x+2 > 9 || x+3 > 9 || x+4 > 9)));
    }
	while(Matrix[x][y] > 0 ||((idea == 1 && (Matrix[x][y+1] > 0 || Matrix[x][y+2] > 0 || Matrix[x][y+3] > 0 || Matrix[x][y+4] > 0)) ||(idea == 0 && (Matrix[x + 1][y] > 0 || Matrix[x + 2][y] > 0 || Matrix[x + 3][y] > 0 || Matrix[x + 4][y] > 0))));
    
	int Ship_5[3][2];
    if(idea == 1)
	{
        Ship_5[0][0] = x;
        Ship_5[0][1] = y;
        Ship_5[1][0] = x;
        Ship_5[1][1] = y + 1;
        Ship_5[2][0] = x;
        Ship_5[2][1] = y + 2;
        Ship_5[3][0] = x;
        Ship_5[3][1] = y + 3;
        Ship_5[4][0] = x;
        Ship_5[4][1] = y + 4;
    }
	else
	{
        Ship_5[0][0] = x;
        Ship_5[0][1] = y;
        Ship_5[1][0] = x + 1;
        Ship_5[1][1] = y;
        Ship_5[2][0] = x + 2;
        Ship_5[2][1] = y;
        Ship_5[3][0] = x + 3;
        Ship_5[3][1] = y;
        Ship_5[4][0] = x + 4;
        Ship_5[4][1] = y;
    }
    Add_PC_Zone(5, 5, Ship_5);
}

void Clear()
{
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < elements; j++)
		{
            Matrix[i][j] = 0 ;
            MyArea[i][j] = 0 ;
        }
}

int NumberOfShips()
{
    int c = 0;
    for(int i = 1; i <= 5; i++)
        if(ZonePC[i].BoxesLeft != 0)
            c++;
    return c;
}

int NumberOfMyShips()
{
    int c = 0;
    for(int i = 1; i <= 5; i++)
        if(Zone[i].BoxesLeft != 0)
            c++;
    return c;
}

bool Attack(int x, int y)
{
    if(Matrix[x][y] > 0)
	{
        int Area = Matrix[x][y];
        ZonePC[Area].BoxesLeft--;
        if(ZonePC[Area].BoxesLeft > 0)
            last_Ship = 1;
        else
            last_Ship = 0;
        last_Ship_id = Area;
        Matrix[x][y] = -1;
        return true;
    }
    return false;
}

bool AttackMe(int x, int y)
{
    if(MyArea[x][y] > 0)
	{
        int Area = MyArea[x][y];
        Zone[Area].BoxesLeft--;
        if(Zone[Area].BoxesLeft > 0)
            last_my_Ship = 1;
        else
            last_my_Ship = 0;
        last_my_Ship_id = Area;
        MyArea[x][y] = -1;
        return true;
    }
    return false;
}

void ShowFull(int type)
{
    cout << " - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << endl;
    cout << " -                     Welcome to BattleShip!                    -" << endl;
    cout << " - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << endl;
    cout << " -          PC Zone:                               My Area:      -" << endl;
    cout << " - - - 0 1 2 3 4 5 6 7 8 9 -           - - - 0 1 2 3 4 5 6 7 8 9 -" << endl;
    for (int i = 0; i < rows; i++)
	{
        cout << " | " << i << " | ";
        for (int j = 0; j < elements; j++)
		{
            if(Matrix[i][j] == -1)
                cout << "X ";
            else if(Matrix[i][j] == 0 || type == 0)
                cout << "* ";
            else if(Matrix[i][j] == 1)
                cout << (char)176 << " ";
            else if(Matrix[i][j] == 2)
                cout << (char)177 << " ";
            else if(Matrix[i][j] == 3)
                cout << (char)178 << " ";
            else if(Matrix[i][j] == 4)
                cout << (char)240 << " ";
            else if(Matrix[i][j] == 5)
                cout << (char)219 << " ";
            else
                cout << Matrix[i][j] << " " ;
        }
        cout << "|           | " << i << " | ";
        for (int j = 0; j < elements; j++)
            if(MyArea[i][j] == -1)
                cout << "X ";
            else if(MyArea[i][j] == 0)
                cout << "* ";
            else if(MyArea[i][j] == 1)
                cout << (char)176 << " ";
            else if(MyArea[i][j] == 2)
                cout << (char)177 << " ";
            else if(MyArea[i][j] == 3)
                cout << (char)178 << " ";
            else if(MyArea[i][j] == 4)
                cout << (char)240 << " ";
            else if(MyArea[i][j] == 5)
                cout << (char)219 << " ";
            else
                cout << MyArea[i][j] << " " ;
        cout << "|" << endl;
    }
    cout << " - - - - - - - - - - - - - -           - - - - - - - - - - - - - -" << endl;
    cout << " | The remaining ships: " << NumberOfShips();
    if(NumberOfShips() == 10)
        cout << " |           | ";
    else
        cout << "  |           | ";
    cout << "The remaining ships: " << NumberOfMyShips();
    if(NumberOfMyShips() == 10)
        cout << " | " << endl;
    else
        cout << "  | " << endl;
    cout << " - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << endl;
}

int main()
{
    srand(time(NULL));
    Clear();

    ZoneRandom();
    ZonaPCRandom();


    int pos1,pos2;
    int posx = -1, posy = -1;
    char prompt = 'n';
    char work = 'n';

    // exite = 0;      // I wanted to get out of the game
    // exite = 1;      // I won
    // exite = 2;      // PC WON

    int exit;
    int hit = 0;
    int Ship_Hit = 0;
    int to_verify;

    Main_Menu();
    
    
	do{
        cout << "You want to get out of the game faster? (y/n): ";
        cin >> work;
    }while(work != 'y' && work != 'n');

    while(1)
	{
        system("cls");
        ShowFull(1);

        if((work == 'y' || work == 'n') && (prompt == 'y' || prompt == 'n'))
		{
            if (hit == 1 && last_Ship == 1)
                cout << " Me: Part of the ship was destroyed (" << last_Ship_id << ")! ... (" << pos1 << "," << pos2 << ")" << endl;
            else if (hit == 1 && last_Ship == 0)
                cout << " Me: The entire ship was destroyed (" << last_Ship_id << ")! ... (" << pos1 << "," << pos2 << ")" << endl;
            else if(hit == 2)
                cout << " Me: No ship at that position!   ... (" << pos1 << "," << pos2 << ")" << endl;

            if(Ship_Hit && last_my_Ship == 1)
                cout << " PC: Part of the ship was destroyed (" << last_my_Ship_id << ")! ... (" << posx << "," << posy << ")" << endl;
            else if(Ship_Hit && last_my_Ship == 0)
                cout << " PC: The entire ship was destroyed (" << last_my_Ship_id << ")! ... (" << posx << "," << posy << ")" << endl;
            else if(posx > -1 && posy > -1)
                cout << " PC: You were attacked at " << posx << "," << posy << " coordinates! " << endl;
            cout << " - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << endl;

            if(prompt == 'n' && NumberOfShips() != 0)
			{
                do{
                    cout << " Me: Please input location: ";
                    cin >> pos1 >> pos2;
                }
				while(pos1 < 0 || pos1 > 10 || pos2 < 0 || pos2 > 10);
                if(Attack(pos1,pos2))
                    hit = 1;
                else
                    hit = 2;
            }
            if(Ship_Hit == 1)
			{
                do{
                   to_verify = getRand0or3();
                }
				while((to_verify == 0 && (posy + 1 >= 10 || MyArea[posx][posy + 1] < 0)) ||(to_verify == 1 && (posx + 1 >= 10 || MyArea[posx + 1][posy] < 0)) ||(to_verify == 2 && (posy - 1 < 0 || MyArea[posx][posy - 1] < 0)) ||(to_verify == 3 && (posx - 1 < 0 || MyArea[posx - 1][posy] < 0)));
                
				if(to_verify == 0 && posy + 1 < 10)
				{
                    posy += 1;
                    if(AttackMe(posx, posy))
                        Ship_Hit = 1;
                    else
                        Ship_Hit = 0;
                }
				else if(to_verify == 1 && posx + 1 < 10)
				{
                    posx += 1;
                    if(AttackMe(posx, posy))
                        Ship_Hit = 1;
                    else
                        Ship_Hit = 0;
                }
				else if(to_verify == 2 && posy - 1 >= 0)
				{
                    posy -= 1;
                    if(AttackMe(posx, posy))
                        Ship_Hit = 1;
                    else
                        Ship_Hit = 0;

                }
				else if(to_verify == 3 && posx - 1 >= 0)
				{
                    posx -= 1;
                    if(AttackMe(posx, posy))
                        Ship_Hit = 1;
                    else
                        Ship_Hit = 0;
                }
				else
				{
                    do{
                        posx = getCoordX();
                        posy = getCoordY();
                    }while(MyArea[posx][posy] < 0);
                    if(AttackMe(posx, posy))
                        Ship_Hit = 1;
                    else
                        Ship_Hit = 0;
                }
            }
			else
			{
                do{
                    posx = getCoordX();
                    posy = getCoordY();
                }
				while(MyArea[posx][posy] < 0);
                if(AttackMe(posx, posy))
                    Ship_Hit = 1;
                else
                    Ship_Hit = 0;
            }

             if(NumberOfShips() == 0)
			 {
                exit = 1;
                break;
            }
            if(NumberOfMyShips() == 0)
			{
                exit = 2;
                break;
            }
        }

        if(work == 'y')
		{
            cout << " - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << endl;
            if (hit == 1 && last_Ship == 1)
                cout << " Me: Part of the ship was destroyed (" << last_Ship_id << ")! ... (" << pos1 << "," << pos2 << ")" << endl;
            else if (hit == 1 && last_Ship == 0)
                cout << " Me: The entire ship was destroyed (" << last_Ship_id << ")! ... (" << pos1 << "," << pos2 << ")" << endl;
            else if(hit == 2)
			{
                cout << " Me: No ship at that position!   ... (" << pos1 << "," << pos2 << ")" << endl;
            }
            if(Ship_Hit && last_my_Ship == 1)
                cout << " PC: Part of the ship was destroyed (" << last_my_Ship_id << ")! ... (" << posx << "," << posy << ")" << endl;
            else if(Ship_Hit && last_my_Ship == 0)
                cout << " PC: The entire ship was destroyed (" << last_my_Ship_id << ")! ... (" << posx << "," << posy << ")" << endl;
            else if(posx > -1 && posy > -1)
                cout << " PC: You were attacked at " << posx << "," << posy << " coordinates! " << endl;
            cout << " - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << endl;
            cout << " Me: Do you want to surrender (y/n) ? " ;
            cin >> prompt;
        }
        if (prompt == 'y')
		{
            exit = 0;
            break;
        }
    }
    system("cls");
    ShowFull(1);
    int My_score=0,Pc_score=0;
    if(exit == 0)
    {
    	cout << " You chose to quit the game !" << endl;
    	getch();
		Main_Menu();	
	}
        
    else if(exit == 1)
	{
		My_score=My_score+1;
		cout << "Congratulations, you won!" << endl;
		cout<<"Your Score: "<<My_score<<endl;
		cout<<"Pc Score: "<<Pc_score<<endl;
		Main_Menu();
	}
    	
    else if(exit == 2)
    {
    	Pc_score=Pc_score+1;
    	cout << " It looks like the computer won!" << endl;
    	cout<<"Your Score: "<<My_score<<endl;
    	cout<<"Pc Score: "<<Pc_score<<endl;
    	Main_Menu();
	}
        

    return 0;
}

