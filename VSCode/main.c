#include<raylib.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int pix[90];
int piy[90];

int xfirst1 = 194, yfisrt1 = 490;
int xfirst2 = 194, yfisrt2 = 490;
int xsecond1 = 572, ysecond1 = 114;
int xsecond2 = 572, ysecond2 = 114;

int first1 = 1, first2 = 1;
int second1 = 81, second2 = 81;

int x_tas = 371;
int y_tas = 29;

int TAS = 0, turn = -1;

int Fcard[4] = {3, 3, 3, 3}, Scard[4] = {3, 3, 3, 3};

bool isp = 0;

int tas() {
    int arr[6], T;
    for (int i = 0; i < 3; i++) {
        arr[i] = -3 + i;
    }
    for (int i = 3; i < 6; i++) {
        arr[i] = -2 + i;
    }
    /*for (int i = 0; i < 6; i++) {
        printf("%d ", arr[i]);
    }*/
    srand(time(0));
    T = rand();
    return arr[T % 6];
}

void set_pos() {
    int C = 47;
    pix[1] = 194;
    piy[1] = 490;
    //111111111111111111111111111111111111111111111111111
    for (int i = 2; i < 10; i++) {
        pix[i] = pix[i - 1] + C;
        piy[i] = piy[i - 1];
    }
    //2222222222222222222222222222222222222222222222222222
    for (int i = 1; i < 10; i++) {
        pix[19 - i] = pix[i];
        piy[19 - i] = piy[i] - C;
    }
    //3333333333333333333333333333333333333333333333333333
    for (int i = 1; i < 10; i++) {
        pix[18 + i] = pix[19 - i];
        piy[18 + i] = piy[19 - i] - C;
    }
    //4444444444444444444444444444444444444444444444444444
    for (int i = 1; i < 10; i++) {
        pix[37 - i] = pix[18 + i];
        piy[37 - i] = piy[18 + i] - C;
    }
    //5555555555555555555555555555555555555555555555555555
    for (int i = 1; i < 10; i++) {
        pix[36 + i] = pix[37 - i];
        piy[36 + i] = piy[37 - i] - C;
    }
    //6666666666666666666666666666666666666666666666666666
    for (int i = 1; i < 10; i++) {
        pix[55 - i] = pix[36 + i];
        piy[55 - i] = piy[36 + i] - C;
    }
    //7777777777777777777777777777777777777777777777777777
    for (int i = 1; i < 10; i++) {
        pix[54 + i] = pix[55 - i];
        piy[54 + i] = piy[55 - i]  - C;
    }
    //8888888888888888888888888888888888888888888888888888
    for (int i = 1; i < 10; i++) {
        pix[73 - i] = pix[54 + i];
        piy[73 - i] = piy[54 + i] - C;
    }
    //9999999999999999999999999999999999999999999999999999
    for (int i = 1; i < 10; i++) {
        pix[72 + i] = pix[73 - i];
        piy[72 + i] = piy[73 - i] - C;
    }
}

int check(int x, int sw) {
    int cnt = 0;
    if (sw == 1) {
        if (first1 + x <= 81 && first1 + x >= 1) {
            cnt = 10;
        }
        if (first2 + x <= 81 && first2 + x >= 1) {
            cnt++;
        }
    }
    else {
        if (second1 + x <= 81 && second1 + x >= 1) {
            cnt = 10;
        }
        if (second2 + x <= 81 && second2 + x >= 1) {
            cnt++;
        }
    }
    return cnt;
}

void checktale(int x, int k) {
    // ro tale bashe hatman
    if (k < 3 && Fcard[0] && GetMouseX() < 162 && GetMouseX() > 17 &&GetMouseY() < 209 && GetMouseY() > 114 && IsMouseButtonPressed(MOUSE_BUTTON_RIGHT)) {
        Fcard[0]--;
        return;
    }
    if (k > 2 && Scard[0] && GetMouseX() < 783 && GetMouseX() > 635 &&GetMouseY() < 209 && GetMouseY() > 114 && IsMouseButtonPressed(MOUSE_BUTTON_RIGHT)) {
        Scard[0]--;
        return;
    }
    if (x == 4) {
        if (k == 1) {
            first1 = 62;
        }
        if (k == 2) {
            first2 = 62;
        }
        if (k == 3) {
            second1 = 62;
        }
        if (k == 4) {
            second2 = 62;
        }
    }
    if (x == 11) {
        if (k == 1) {
            first1 = 49;
        }
        if (k == 2) {
            first2 = 49;
        }
        if (k == 3) {
            second1 = 49;
        }
        if (k == 4) {
            second2 = 49;
        }
    }
    if (x == 20) {
        if (k == 1) {
            first1 = 78;
        }
        if (k == 2) {
            first2 = 78;
        }
        if (k == 3) {
            second1 = 78;
        }
        if (k == 4) {
            second2 = 78;
        }
    }
    if (x == 33) {
        if (k == 1) {
            first1 = 71;
        }
        if (k == 2) {
            first2 = 71;
        }
        if (k == 3) {
            second1 = 71;
        }
        if (k == 4) {
            second2 = 71;
        }
    }
    if (x == 62) {
        if (k == 1) {
            first1 = 4;
        }
        if (k == 2) {
            first2 = 4;
        }
        if (k == 3) {
            second1 = 4;
        }
        if (k == 4) {
            second2 = 4;
        }
    }
    if (x == 49) {
        if (k == 1) {
            first1 = 11;
        }
        if (k == 2) {
            first2 = 11;
        }
        if (k == 3) {
            second1 = 11;
        }
        if (k == 4) {
            second2 = 11;
        }
    }
    if (x == 78) {
        if (k == 1) {
            first1 = 20;
        }
        if (k == 2) {
            first2 = 20;
        }
        if (k == 3) {
            second1 = 20;
        }
        if (k == 4) {
            second2 = 20;
        }
    }
    if (x == 71) {
        if (k == 1) {
            first1 = 33;
        }
        if (k == 2) {
            first2 = 33;
        }
        if (k == 3) {
            second1 = 33;
        }
        if (k == 4) {
            second2 = 33;
        }
    }
}

void set_card(int poss, int who) {
    if (poss != 9 && poss != 17 && poss != 25 && poss != 52 && poss != 65 && poss != 73) {
        return;
    }
    int T;
    srand(time(0));
    T = rand() % 4;
    if (who == 1) {
        Fcard[T]++;
    }
    else {
        Scard[T]++;
    }
}

/*void checkcard() {

}*/

int check_zarib(int who) {
    if (who == 1) {
        if (Fcard[1] && GetMouseX() < 162 && GetMouseX() > 17 &&GetMouseY() < 320 && GetMouseY() > 224 && IsMouseButtonPressed(MOUSE_BUTTON_RIGHT)) {
            Fcard[1]--;
            return TAS;       
        }
        else {
            return 0;
        }
    }
    else {
        if (Scard[1] && GetMouseX() < 783 && GetMouseX() > 635 &&GetMouseY() < 320 && GetMouseY() > 224 && IsMouseButtonPressed(MOUSE_BUTTON_RIGHT)) {
            Scard[1]--;
            return TAS;       
        }
        else {
            return 0;
        }
    }
}

int main() {
    const int windowwidth = 800;
    const int windowheight = 600;
    
    InitWindow(windowwidth, windowheight, "my game");
    SetTargetFPS(60);
    
    Texture2D board = LoadTexture("resources/final_board.png"); 

    Texture2D sefid1 = LoadTexture("resources/sefid1.png"); 
    Texture2D sefid2 = LoadTexture("resources/sefid2.png"); 
    Texture2D siah1 = LoadTexture("resources/siah1.png"); 
    Texture2D siah2 = LoadTexture("resources/siah2.png"); 
    set_pos();
    bool raft = 1;
    while(!WindowShouldClose()) {
        
        // premium
        if (GetMouseX() < 449 && GetMouseX() > 355 &&GetMouseY() < 580 && GetMouseY() > 550 && IsMouseButtonPressed(MOUSE_BUTTON_RIGHT)) {
            if (!isp) {
                sefid1 = LoadTexture("resources/sefidp.png"); 
                sefid2 = LoadTexture("resources/sefidp.png"); 
                siah1 = LoadTexture("resources/siahp.png"); 
                siah2 = LoadTexture("resources/siahp.png");
                isp = 1;
            }
            else {
                sefid1 = LoadTexture("resources/sefid1.png"); 
                sefid2 = LoadTexture("resources/sefid2.png"); 
                siah1 = LoadTexture("resources/siah1.png"); 
                siah2 = LoadTexture("resources/siah2.png");
                isp = 0;
            }
        }
        
        // click on tas
        if (GetMouseX() < 431 && GetMouseX() > 368 &&GetMouseY() < 90 && GetMouseY() > 27 && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
            raft = 0;
            /*if (tas() == -3) {
                TAS = tas();
            }
            if (tas() == -2) {
                TAS = tas();
            }
            if (tas() == -1) {
                TAS = tas();
            }
            if (tas() == 1) {
                TAS = tas();
            }
            if (tas() == 2) {
                TAS = tas();
            }
            if (tas() == 3) {
                TAS = tas();
            }*/
            TAS = tas();
            turn *= -1;
        }

        //kodom mohre
        if (turn == 1 && !raft) {
            if ((IsKeyPressed(KEY_A) && check(TAS, turn) == 11) || check(TAS, turn) == 10) {
                first1 += TAS;
                first1 += check_zarib(1);
                checktale(first1, 1);
                set_card(first1, 1);
                xfirst1 = pix[first1];
                yfisrt1 = piy[first1];
                raft = 1;
            }
            else if((IsKeyPressed(KEY_B) && check(TAS, turn) == 11) || check(TAS, turn) == 1) {
                first2 += TAS;
                first2 += check_zarib(1);
                checktale(first2, 2);
                set_card(first2, 1);
                xfirst2 = pix[first2];
                yfisrt2 = piy[first2];
                raft = 1;
            }
        }
        else if(!raft){
            if ((IsKeyPressed(KEY_A) && check(TAS, turn) == 11) || check(TAS, turn) == 10) {
                second1 += TAS;
                check_zarib(2);
                checktale(second1, 3);
                set_card(second1, 2);
                xsecond1 = pix[second1];
                ysecond1 = piy[second1];
                raft = 1;
            }
            else if((IsKeyPressed(KEY_B) && check(TAS, turn) == 11) || check(TAS, turn) == 1) {
                second2 += TAS;
                check_zarib(2);
                checktale(second2, 4);
                set_card(second2, 2);
                xsecond2 = pix[second2];
                ysecond2 = piy[second2];
                raft = 1;
            }
        }
        
        /////////////////////////////////////////////////////////////
       /* FILE *inputfile;
        FILE *outputfile;
        inputfile = fopen("input.txt", "rt");
        outputfile = fopen("output.txt", "wt");
        fprintf("outputfile", "%d %d %d %d %d", turn, first1, first2, second1, second2);
        fclosall();*/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        BeginDrawing();
        ClearBackground(RAYWHITE); //color(245, 245, 245, 255)
        DrawTexture(board, windowwidth/2 - board.width/2, windowheight/2 - board.height/2, WHITE);
        
        //mohre ha
        DrawTexture(sefid1, xfirst1, yfisrt1, WHITE);
        DrawTexture(sefid2, xfirst2, yfisrt2, WHITE);
        DrawTexture(siah1, xsecond1, ysecond1, WHITE);
        DrawTexture(siah2, xsecond2, ysecond2, WHITE);

        //nobat
        if (turn == -1) {
            DrawText("WHITE :", 81, 48, 30, MAROON);
        }
        else {
            DrawText("BLACK :", 81, 48, 30, MAROON);
        }
        DrawText(TextFormat("%i", TAS), 387, 37, 40, BLACK);

        //bepors kodom mohre
        if (check(TAS, turn) > 10 && TAS) {
            DrawRectangle(532, 25, 200, 60, GREEN);
            DrawText("which on?", 540, 27, 20, BLACK);
            DrawText("press A or B", 540, 48, 20, BLACK);
        }

        // kartha
        DrawText(TextFormat("%i", Fcard[0]), 24, 119, 40, WHITE);
        DrawText(TextFormat("%i", Fcard[1]), 24, 230, 40, WHITE);
        DrawText(TextFormat("%i", Fcard[2]), 24, 342, 40, WHITE);
        DrawText(TextFormat("%i", Fcard[3]), 24, 453, 40, WHITE);

        DrawText(TextFormat("%i", Scard[0]), 641, 119, 40, WHITE);
        DrawText(TextFormat("%i", Scard[1]), 641, 230, 40, WHITE);
        DrawText(TextFormat("%i", Scard[2]), 641, 342, 40, WHITE);
        DrawText(TextFormat("%i", Scard[3]), 641, 453, 40, WHITE);

        // premium
        DrawText("PREMIUM", 375, 567, 10, GRAY);
        EndDrawing();
    }
    UnloadTexture(board);
    UnloadTexture(sefid1);
    UnloadTexture(sefid2);
    UnloadTexture(siah1);
    UnloadTexture(siah2);
    CloseWindow();
    return 0; 
}