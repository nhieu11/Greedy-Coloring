#include <iostream>
#include <cstring>
#include <fstream> 
#define size 30
using namespace std;
//Bui Ngoc Hieu 20187319
int n,m, a[size][size],colorsAmount=0,c[size]; //c[i] : mau cua dinh i, colorsAmount : mau va so mau

void Input() {
	int i,j;
	ifstream graphin("dothi.txt");
	if (graphin.is_open()) {
		graphin >> n >> m;
		for(int b=1; b<=m ; b++) { //dua ve ma tran 
			graphin >> i;
			graphin >> j;
			a[i][j]=1;
			a[j][i]=1;
		}
		graphin.close();
	} else cout << "file not found"; 
}

void Solution() { 
	int check;
	for(int i=1; i<=n; i++){ //xet tung hang
		
		while(!c[i]) { //while(1) neu dinh chua co mau
	
			colorsAmount++; //Dem so mau
			c[i]=colorsAmount; //Gan mau dinh dang xet = mau moi
			for(int j=i+1; j<=n; j++){ //Kiem tra xem nhung dinh nao co the gan bang mau sm nua khong, xet tung cot, dung it mau nhat co the
				if((a[i][j]==0)&&(c[j]==0)) { // 2 dinh khong giao nhau va dinh j chua c� mau
					
				check=1;
					
					for(int k=i+1; k<j; k++){
						
						if((a[k][j]==1)&&(c[i]==c[k])) { //Neu dinh moi xet (theo hang) giao nhau (nhin tren do thi la theo dinh dung truoc no) va 2 mau cua 2 dinh cu trung nhau 
							check=0;  
							break;
						}
						
					}
					if(check==1) c[j]=colorsAmount;
				}
			}
				
		}
	}
		
}
void Output() { 
	ofstream graphout("dothitomau.dot");
	graphout<<"graph dothi" << endl;  
	graphout<<"{"<< endl;
	for(int i=1; i<=n; i++){
		graphout << i << " [fillcolor=";
					switch (c[i])
					{
					    case 1: graphout << "green";
					        break;
					    case 2: graphout << "red";
					        break;
					    case 3: graphout << "yellow";
					        break;   
					    case 4: graphout << "moccasin";
					        break;   
					    case 5: graphout << "LightCyan";	
					        break; 
						case 6: graphout << "LightPink";
					        break;  
					    case 7: graphout << "LavenderBlush4";	
					        break;
						case 8: graphout << "orange";	
					        break;  
					    default: graphout << "black";
					} 	

		graphout << ", style=filled];" << endl;
		
		}
   		int i,j;
		ifstream graphin("dothi.txt");
			graphin >> n >> m;
		for(int b=1; b<=m ; b++) { 
			graphin >> i;
			graphin >> j;
			graphout << i <<" -- "<< j << ";" << endl ;
		}
		graphout<<"}"<< endl;
		graphout.close();
}
int main() {
	Input();
	Solution();
	Output();
	return 0;
}
