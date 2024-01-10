#include <iostream>
#include <stdio.h>
#include <string>
#include <raylib.h>
#include <cmath>

using namespace std;

#define EMPTY 0
#define WHITEPAWN 1
#define WHITEKNIGHT 2
#define WHITEBISHOP 3
#define WHITEROOK 4
#define WHITEQUEEN 5
#define WHITEKING 6
#define BLACKPAWN 7
#define BLACKKNIGHT 8
#define BLACKBISHOP 9
#define BLACKROOK 10
#define BLACKQUEEN 11
#define BLACKKING 12




class Board {
    public:
        int arr_board[8][8] ={0}; // An array based board in case I want it 
        int white_attack[8][8]; // Squares that the white pieces attack
        int black_attack[8][8]; // squares that the black pieces attack

        /* Changes the board to a default chess board */
        void init_default_board(){
            
            for (int i=0; i<8; i++) // init pawns
            {
                arr_board[1][i]= WHITEPAWN;
                arr_board[6][i]= BLACKPAWN;
            }

            // init rooks
            arr_board[0][0] = WHITEROOK;
            arr_board[0][7] = WHITEROOK;
            arr_board[7][0] = BLACKROOK;
            arr_board[7][7] = BLACKROOK;

            // init knight
            arr_board[0][1] = WHITEKNIGHT;
            arr_board[0][6] = WHITEKNIGHT;
            arr_board[7][1] = BLACKKNIGHT;
            arr_board[7][6] = BLACKKNIGHT;

            // init bishops
            arr_board[0][2] = WHITEBISHOP;
            arr_board[0][5] = WHITEBISHOP;
            arr_board[7][2] = BLACKBISHOP;
            arr_board[7][5] = BLACKBISHOP;

            // init queens and kings
            arr_board[0][3] = WHITEQUEEN;
            arr_board[0][4] = WHITEKING;
            arr_board[7][3] = BLACKQUEEN;
            arr_board[7][4] = BLACKKING;
        }

        void print_board(){
            for (int i=0; i<8; i++)
            {
                printf("Row %d: ", i);

                for (int j=0; j<8; j++)
                {
                    printf("%d | ", arr_board[i][j]);
                }
                printf("\n");
            }
            return;
        }


};

void DrawBoard(int width, int height, Color white, Color black){
    /* Draws a chess board in the center of the screen 
    int width - width of screen in pixels
    int height - width of screen in pixels
    Color white - color of the white squares
    Color black - color of black squares 
    returns: void               */
    for (int i=0; i<8; i++){
        for (int j=0; j<8; j++){

            if ((i+j)% 2 == 0){ // Draw black squares
                DrawRectangle((0.1f)*width+j*(0.1f)*width, (0.1f)*height+i*(0.1f)*height, (0.1f)*width,(0.1f)*height, black);
            }
            else{ // Draw white Squares
                DrawRectangle((0.1f)*width+j*(0.1f)*width, (0.1f)*height+i*(0.1f)*height, (0.1f)*width,(0.1f)*height, white);
            }   
        }
    }
    return;
}

void DrawPieces(Texture2D textures[13], int board[][8], int width, int height, Rectangle source){
    /* Draws pieces onto a chess board of width and height 
    Texture2D textures - an array of chess image textures where the array index is the same as the declaration for the piece
    int width - width of board
    int height - height of board
    Rectangle source - rectangle that represents the size of the texture file
    returns - void          */
    for (int i=0; i<8; i++){
        for (int j=0; j<8; j++){

            switch(board[i][j]) { // check which piece it is
                case(WHITEPAWN):
                    DrawTexturePro(textures[WHITEPAWN], source, {(0.1f)*width+j*(0.1f)*width,(0.1f)*height+(7-i)*(0.1f)*height, (0.1f)*width, 0.1f*height}, (Vector2){0,0}, 0.0f, {0xff,0xff,0xff,0xff});
                    break;
                case(WHITEKNIGHT):
                    DrawTexturePro(textures[WHITEKNIGHT], source, {(0.1f)*width+j*(0.1f)*width,(0.1f)*height+(7-i)*(0.1f)*height, (0.1f)*width, 0.1f*height}, (Vector2){0,0}, 0.0f, {0xff,0xff,0xff,0xff});
                    break;
                case(WHITEBISHOP):
                    DrawTexturePro(textures[WHITEBISHOP], source, {(0.1f)*width+j*(0.1f)*width,(0.1f)*height+(7-i)*(0.1f)*height, (0.1f)*width, 0.1f*height}, (Vector2){0,0}, 0.0f, {0xff,0xff,0xff,0xff});
                    break;
                case(WHITEROOK):
                    DrawTexturePro(textures[WHITEROOK], source, {(0.1f)*width+j*(0.1f)*width,(0.1f)*height+(7-i)*(0.1f)*height, (0.1f)*width, 0.1f*height}, (Vector2){0,0}, 0.0f, {0xff,0xff,0xff,0xff});
                    break;
                case(WHITEQUEEN):
                    DrawTexturePro(textures[WHITEQUEEN], source, {(0.1f)*width+j*(0.1f)*width,(0.1f)*height+(7-i)*(0.1f)*height, (0.1f)*width, 0.1f*height}, (Vector2){0,0}, 0.0f, {0xff,0xff,0xff,0xff});
                    break;
                case(WHITEKING):
                    DrawTexturePro(textures[WHITEKING], source, {(0.1f)*width+j*(0.1f)*width,(0.1f)*height+(7-i)*(0.1f)*height, (0.1f)*width, 0.1f*height}, (Vector2){0,0}, 0.0f, {0xff,0xff,0xff,0xff});
                    break;
                case(BLACKPAWN):
                    DrawTexturePro(textures[BLACKPAWN], source, {(0.1f)*width+j*(0.1f)*width,(0.1f)*height+(7-i)*(0.1f)*height, (0.1f)*width, 0.1f*height}, (Vector2){0,0}, 0.0f, {0xff,0xff,0xff,0xff});
                    break;
                case(BLACKKNIGHT):
                    DrawTexturePro(textures[BLACKKNIGHT], source, {(0.1f)*width+j*(0.1f)*width,(0.1f)*height+(7-i)*(0.1f)*height, (0.1f)*width, 0.1f*height}, (Vector2){0,0}, 0.0f, {0xff,0xff,0xff,0xff});
                    break;
                case(BLACKBISHOP):
                    DrawTexturePro(textures[BLACKBISHOP], source, {(0.1f)*width+j*(0.1f)*width,(0.1f)*height+(7-i)*(0.1f)*height, (0.1f)*width, 0.1f*height}, (Vector2){0,0}, 0.0f, {0xff,0xff,0xff,0xff});
                    break;
                case(BLACKROOK):
                    DrawTexturePro(textures[BLACKROOK], source, {(0.1f)*width+j*(0.1f)*width,(0.1f)*height+(7-i)*(0.1f)*height, (0.1f)*width, 0.1f*height}, (Vector2){0,0}, 0.0f, {0xff,0xff,0xff,0xff});
                    break;
                case(BLACKQUEEN):
                    DrawTexturePro(textures[BLACKQUEEN], source, {(0.1f)*width+j*(0.1f)*width,(0.1f)*height+(7-i)*(0.1f)*height, (0.1f)*width, 0.1f*height}, (Vector2){0,0}, 0.0f, {0xff,0xff,0xff,0xff});
                    break;
                case(BLACKKING):
                    DrawTexturePro(textures[BLACKKING], source, {(0.1f)*width+j*(0.1f)*width,(0.1f)*height+(7-i)*(0.1f)*height, (0.1f)*width, 0.1f*height}, (Vector2){0,0}, 0.0f, {0xff,0xff,0xff,0xff});
                    break;
            }

        }
    }

}
 void FindIndex(int width, int height, Vector2 position, int square[2]){
    /* Finds what index of the board is selected best on the cursor position and represents that in square
    Vector2 position - position of mouse 
    int width - width of the boundary to draw board
    int height - height of the boundary to draw board
    int square[2] - array with each value set to -1, meant to represent the index of the square on the actual chess board
    returns none
    */
    square[0] = (int)floor((position.x -(0.1f)*width)/((0.1f)*width));
    square[1] = (int)floor(((height-position.y) -(0.1f)*height)/((0.1f)*height));
    printf("Position.x: %f, Position.y: %f\n", position.x, position.y);

}

int main () {
    /* Initalize variables and Window */
    int screenWidth = 1920;
    int screenHeight = 1080;

    InitWindow(screenWidth, screenHeight, "CHASE CHESS");
    SetTargetFPS(60);

    /* Initialize chess board and test*/
    Board myBoard;
    myBoard.init_default_board();
    myBoard.print_board();

    /* Load Images for Pieces */
    Texture2D textures[13];
    textures[WHITEPAWN] = LoadTexture("textures/wP.png");
    textures[WHITEKNIGHT] = LoadTexture("textures/wN.png");
    textures[WHITEBISHOP] = LoadTexture("textures/wB.png");
    textures[WHITEROOK] = LoadTexture("textures/wR.png");
    textures[WHITEQUEEN] = LoadTexture("textures/wQ.png");
    textures[WHITEKING] = LoadTexture("textures/wK.png");
    textures[BLACKPAWN] = LoadTexture("textures/bP.png");
    textures[BLACKKNIGHT] = LoadTexture("textures/bN.png");
    textures[BLACKBISHOP] = LoadTexture("textures/bB.png");
    textures[BLACKROOK]= LoadTexture("textures/bR.png");
    textures[BLACKQUEEN] = LoadTexture("textures/bQ.png");
    textures[BLACKKING] = LoadTexture("textures/bK.png");
    

    Rectangle source = {0, 0, 60, 60}; //size of original texture which we will use to scale
    
    Color ChessGreen = {0x76, 0x86, 0x56, 0xff};
    Color ChessBrown = {0xee, 0xee, 0xd2, 0xff};

    int player_turn = 0; // 0= white, 1 = black
    bool piece_selected = false; 


    /* Main Game Loop */
    while (WindowShouldClose() == false){

        if (!piece_selected && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
            int square[2]= {-1,-1};
            FindIndex(screenWidth, screenHeight, GetMousePosition(), square);
            printf("X: %d, Y: %d\n", square[0],square[1]);
        }

        BeginDrawing();
        ClearBackground(BLACK);
        
        DrawBoard(screenWidth, screenHeight, ChessGreen, ChessBrown);
        DrawPieces(textures, myBoard.arr_board, screenWidth, screenHeight, source);

        EndDrawing();
    }
    
    /* Unload Textures */
    for (int i=0; i<13; i++){
        UnloadTexture(textures[i]);
    }
    
    CloseWindow();
    return 0;
}