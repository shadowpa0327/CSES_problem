#include<bits/stdc++.h>
using namespace std;

class eight_queen{
    private:
    const bool available;
    const int norm;
    int square_size;
    int solution_number;
    vector<bool>column_state;
    vector<bool>left_diagonal_state;
    vector<bool>right_diagonal_state;
    vector<int>columninrow;
    vector<vector<char> >map;
    public:
    eight_queen(int square):square_size(square),norm(square-1),available(true),solution_number(0)
    {}
    void initial();
    void put_queen(int row);
    void solve();
    void create_map();
    bool check_available(int row,int column);
    bool check_correct_answer();
    int get_solution_number(){ return solution_number;}
};

bool eight_queen::check_available(int row,int column){
    if(column_state[column]==available&&left_diagonal_state[row+column]==available&&right_diagonal_state[row-column+norm]==available&&map[row][column]!='*')
        return true;

    return false;    
}

bool eight_queen::check_correct_answer(){
    for(int i=0;i<square_size;i++){
        if(columninrow[i]<0)
            return false;
    }
    return true;
}

void eight_queen::create_map(){
    for(int i=0;i<square_size;i++){
        for(int j=0;j<square_size;j++){
            //cout<<"hi"<<endl;
            cin>>map[i][j];
        }
    }
}

void eight_queen::solve(){
        
    solution_number++;
    /*cout<<"solution:"<<solution_number<<endl;
    for(int i=0;i<square_size;i++){
        for(int j=0;j<square_size;j++){
            if(j==columninrow[i])
                cout<<'x';
            else
                cout<<'*';
            cout<<' ';
        }
        cout<<endl;
    }*/
}


void eight_queen::initial(){
    map.resize(square_size,vector<char>(square_size));
    column_state.resize(square_size,true);
    left_diagonal_state.resize(2*square_size-1,true);
    right_diagonal_state.resize(2*square_size-1,true);
    columninrow.resize(square_size,-1);
}

void eight_queen::put_queen(int row){

   
    for(int col=0;col<square_size;col++){
       
        if(check_available(row,col)){
            column_state[col]=false;
            left_diagonal_state[row+col]=false;      
            right_diagonal_state[row-col+norm]=false;
            columninrow[row]=col; 

            if(row<square_size-1)
                put_queen(row+1);
            else
                solution_number++;
            
            
            column_state[col]=true;
            left_diagonal_state[row+col]=true;
            right_diagonal_state[row-col+norm]=true;
        }
    }
}

int main(){
    eight_queen eq(8);
    eq.initial();
    eq.create_map();
    eq.put_queen(0);
    
    cout<<eq.get_solution_number();
    return 0;
}

//https://www.itread01.com/content/1550644567.html
//八皇后解法:
//類似排列組合概念,每一row 代表一個bit,然後透過對column進行尋訪,並判斷column及diagonal是否為available,決定是否可以放在這個位置,直到n個位置都被放滿