int check_chain(char** A,int **F,int r1,int r2,int c1, int c2,player *p1,player *p2,int right,int left,int up,int down,int check);
int check_box(char **A,int r1,int r2,int c1,int c2,int **F,int flag,player *p1,player *p2){
    int check=0,checkinv =0,right=0,left=0,up=0,down=0;
    if(r1==r2){
        int c = c1<c2 ? c1:c2;
        if(r1-1>=2&&A[r1-1][c1]==-70&&A[r1-1][c2]==-70&&A[r1-rows_c][c+1]==-51){   //check the edge and that the there is a box
                A[r1-1][c+1]=178;
                F[r1-1][c+1]=flag;      //make box with players colour
                check++;    //calculate no of boxes 
                down=1;     //dertermine the direction which is sent to check_chain
        }
        if(r1+1<rows&&A[r1+1][c1]==-70&&A[r1+1][c2]==-70&&A[r1+rows_c][c+1]==-51){  //check the edge and that the there is a box
            A[r1+1][c+1]=178;
            F[r1+1][c+1]=flag;          //make box with players colour
            check++;        //calculate no of boxes
            up=1;           //dertermine the direction which is sent to check_chain
        }
    }
    else if(c1==c2){
        int r = r1<r2 ? r1:r2;
        if(c1-1>=2&&A[r1][c1-1]==-51&&A[r2][c1-1]==-51&&A[r+1][c1-cols_c]==-70){    //check the edge and that the there is a box
            A[r+1][c1-1]=178;
            F[r+1][c1-1]=flag;          //make box with players colour
            check++;        //calculate no of boxes
            right=1;        //dertermine the direction which is sent to check_chain
        }
        if(c1+1<cols&&A[r1][c1+1]==-51&&A[r2][c1+1]==-51&&A[r+1][c1+cols_c]==-70){  //check the edge and that the there is a box
            A[r+1][c1+1]=178;
            F[r+1][c1+1]=flag;          //make box with players colour
            check++;        //calculate no of boxes
            left=1;         //dertermine the direction which is sent to check_chain
        }
    }
    movecount++;


    if (check>0) {      //if there is a box update players score and check if there is a chain and make the player get another turn
            if (flag ==0) {p1->score+=check;printf("mina");sleep(3);check_chain(A,F,r1,r2,c1,c2,p1,p2,right,left,up,down,0);printf("mina");sleep(3); return flag;}
            else if (flag ==1) {p2->score+=check;printf("mina");sleep(3);check_chain(A,F,r1,r2,c1,c2,p1,p2,right,left,up,down,0);printf("mina");sleep(3);  return flag;}
    }
    else {movecount = 0;
                if(r1 ==(n+1)){printf("YARABB");sleep(2);}

            return flag^=1;         //change player turn
}}


void check_box_inv(char** A,int r1,int r2,int c1,int c2,int** F,int flag,player *p1,player *p2){
    int check =0;
    if(r1==r2){
        int c = c1<c2 ? c1:c2;

        if(A[r1-1][c1]==-70&&A[r1-1][c2]==-70&&A[r1-rows_c][c+1]==-51){
                    A[r1-1][c+1]=' ';
                    F[r1-1][c+1]=2;
                    check++;

        }
        if(A[r1+1][c1]==-70&&A[r1+1][c2]==-70&&A[r1+rows_c][c+1]==-51){
            A[r1+1][c+1]=' ';
            F[r1+1][c+1]=2;
            check++;
        }
    }
    else if(c1==c2){
        int r = r1<r2 ? r1:r2;
        if(A[r1][c1-1]==-51&&A[r2][c1-1]==-51&&A[r+1][c1-cols_c]==-70){
            A[r+1][c1-1]=' ';
            F[r+1][c1-1]=2;
            check++;
        }
        if(A[r1][c1+1]==-51&&A[r2][c1+1]==-51&&A[r+1][c1+cols_c]==-70){
            A[r+1][c1+1]=' ';
            F[r+1][c1+1]=2;
            check++;
        }
    }
    if (check>0) {
            if (flag ==0) {p1->score-=check;}
            else if (flag ==1) {p2->score-=check;}
    }
}



void dfsmove(char **A,int **F,int r1,int r2,int c1,int c2,int right, int left, int up , int down,player *p1,player *p2/*int *undo*/){
    int c,r;
    if(r1==r2)
        c= c1<c2 ? c1:c2;
    else if(c1==c2)
        r = r1<r2 ? r1:r2;
    if(right){
        A[r+1][c1]=-70;
        F[r+1][c1]=flag;
        A[r+1][c1+1]=178;
        F[r+1][c1+1]=flag;
    }
    else if(left){
        A[r+1][c1]=-70;
        F[r+1][c1]=flag;
        A[r+1][c1-1]=178;
        F[r+1][c1-1]=flag;
    }
    else if(up){
        A[r1][c+1]=-51;
        F[r1][c+1]=flag;
        A[r1-1][c+1]=178;
        F[r1-1][c+1]=flag;
    }
    else if(down){
        A[r1][c+1]=-51;
        F[r1][c+1]=flag;
        A[r1+1][c+1]=178;
        F[r1+1][c+1]=flag;
    }

    if (flag ==0) {p1->score++; p1->moves++;}
    else if (flag ==1) {p2->score++; p2->moves++;}
    //store_move(r1,r2,c1,c2,undo,p1,p2);
}
