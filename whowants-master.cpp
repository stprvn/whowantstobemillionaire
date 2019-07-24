#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
using namespace std;
void fifty(string opsio[4],char answ){		//fungsi bantuan 50-50 bila jawaban yang benar antara B dan C
	cout<<"Anda Memilih Bantuan 50-50\n";
	if(answ == 'a' || answ == 'c'){
		cout<<endl<<opsio[0]<<"\t"<<opsio[2]<<endl;
	}else if(answ == 'b' || answ == 'd'){
		cout<<endl<<opsio[1]<<"\t"<<opsio[3]<<endl;
	}
}

void audiens(char answ){		//fungsi bantuan polling audiens
	cout<<"Anda Memilih Polling Audiens\n";
	cout<<"Parameter Voting telah siap\n";
	cout <<"Menurut Audiens Jawaban yang benar adalah "<<endl;
	if(answ == 'a'){
		cout<<"Yang memilih A = 67%"<<endl;
		cout<<"Yang memilih B = 3%"<<endl;
		cout<<"Yang memilih C = 10%"<<endl;
		cout<<"Yang memilih D = 20%"<<endl;
	}else if(answ == 'b'){
		cout<<"Yang memilih A = 3%"<<endl;
		cout<<"Yang memilih B = 67%"<<endl;
		cout<<"Yang memilih C = 10%"<<endl;
		cout<<"Yang memilih D = 20%"<<endl;
	}else if(answ == 'c'){
		cout<<"Yang memilih A = 20%"<<endl;
		cout<<"Yang memilih B = 3%"<<endl;
		cout<<"Yang memilih C = 67%"<<endl;
		cout<<"Yang memilih D = 10%"<<endl;
	}else if(answ == 'd'){
		cout<<"Yang memilih A = 10%"<<endl;
		cout<<"Yang memilih B = 3%"<<endl;
		cout<<"Yang memilih C = 20%"<<endl;
		cout<<"Yang memilih D = 67%"<<endl;
	}
}

void telpon(char answ){		//fungsi bantuan telefon
	cout<<"Hallo......\n";
	cout<<"Hmmmm, Pertanyaan Yang bagus... Saya pikir jawabannya adalah....."<<answ<<endl;
}

void highscore (string nama,int hadiah){	//fungsi untuk melihat highscore yang di baca dari txt bernama highscore.txt
	ofstream fout;
	fout.open("highscore.txt",ios::app);
	fout << nama<<endl;
	fout << hadiah<<endl;
	fout.close();
}

void petunjuk()
{
	cout<<"\t\t\t\t\t\tPetunjuk\n\n\t\t1. Input opsi/jawaban hanya di lakukan dengan menggunakan keyboard"<<endl;
	cout<<"\t\t2. Checkpoint terdiri dari 2 bagian yaitu pada soal 5 dan 10 ."<<endl;
	cout<<"\t\t3. Jika anda ingin menyerah ditengah permainan silahkan ketik 'o'."<<endl;
	cout<<"\t\t4. Terdapat bantuan 50-50,polling,dan call friend ."<<endl;
	cout<<"\t\t5. Game ini hanya fiktif belaka,tidak akan menghasilkan uang dalam bentuk apapun"<<endl;
	cout<<" \n\n\t\t\t\t  ====SELAMAT BERMAIN=====\n\n\n\n\n\n\n\n\n\n\n\n\n";
	system("pause");
	system("cls");
}
void hadiah(int x,string nama)
{
	if(x<5)
	{
		cout<<"Maaf anda tidak memenangkan uang sepeserpun.\nCoba lagi !";
		highscore(nama,0);
	}else if(x<10)
	{
		cout<<"anda masih dapat membawa pulang uang sebesar Rp.1.000.000,-";
		highscore(nama,1000000);
	}else if(x<15)
	{
		cout<<"anda masih dapat membawa pulang uang sebesar Rp.30.000.000,-";
		highscore(nama,30000000);
	}else
	{
		cout<<" \n\t\tSELAMAT ANDA BERHASIL MEMENANGKAN HADIAH SEBESAR"<<endl;
		cout<<" \t  ==========S A T U   M I L I A R   R U P I A H============"<<endl<<endl;
		highscore(nama,1000000000);
	}
}

void garis(){
	cout<<"============================================================================================================"<<endl;
}

void quicksort(int score[], string name[], int kiri, int kanan) {
  int temp_score = 0, i = kiri, j = kanan;
  int pivot = score[(kiri + kanan) / 2];
  string temp_name;
  //Pengurutan data berdasar Pivot
  while (i <= j) {
    while (score[i] > pivot) {
      i++;
    }
    while (score[j] < pivot) {
      j--;
    }
    if (i <= j) {
      temp_score = score[i];
      score[i] = score[j];
      score[j] = temp_score;
      temp_name = name[i];
      name[i] = name[j];
      name[j] = temp_name;
      i++;
      j--;
    }
  }
  //Rekursif
  if (kiri < j) {
    quicksort(score, name, kiri, j);
  }
  if (i < kanan) {
    quicksort(score, name, i, kanan);
  }
}


int main (){
	
	_begin:
	int i;
	string nama;
	string name[100];
	int score[100];
	cout << "Masukan Nama Anda = ";
	getline (cin,nama);
	if(nama==""){
		system("CLS");
		goto _begin;
	}
	system ("CLS");
	char start;
	cout<<"\n\n\n\n\n\n\n\t\t\t\t WELCOME  TO  WHO  WANTS  TO  BE  MILLIONAIRE\n\n";
	cout<<"\n\n\n\t\t\t  type 'p' to play game and 'h' to view the highscore ";
	cout<<"\n\n\n\n\n\t\t\t\t\t\t    ";cin>>start;
	system ("CLS");

	if(start=='p')
	{
		system("cls");
		petunjuk();
		goto _1M;
	}else if(start=='h')
	{	
		string cari;
		int i=0;
		for (int i=0;i<100;i++)
		{
			name[i]="";
			score[i]=0;
		}
		ifstream highscore;
		highscore.open("highscore.txt");
		while(!highscore.eof())
		{
			getline(highscore,name[i]);
			highscore >> score[i];
			highscore.ignore(100,'\n');
			i++;
		}
		quicksort(score,name,0,99);
		cout<<"\tNAMA\t\t|\t\tSCORE\t\t"<<endl;
		cout<<"========================================================"<<endl;
		for(int m=0;m<25;m++)
		{
			cout<<name[m]<<"\t\t\t\t"<<"Rp "<<score[m]<<endl;
		}
		cout<<"\t\t\t\t\t\t\tCARI : ";
		cin.ignore();
		getline(cin,cari);
		system("cls");
		cout<<"\tNAMA\t\t|\t\tSCORE\t\t"<<endl;
		cout<<"========================================================"<<endl;
		for(int m=0;m<100;m++)
		{
			if(cari==name[m]&&cari!=""){
				cout<<cari<<"\t\t\t\t"<<"Rp "<<score[m]<<endl;	
			}
		}
		cout<<"\n\n";
		system ("PAUSE");
		system ("CLS");	
		goto _begin;
	}else
	{
		system("cls");
		system("pause");
		return 0;
	}

//kamus
_1M:
	char main;
	int p=0; 	//p  adalah indeks checkpoint dimana checkpoint akan diterima jike melewati soal ke 5 dan 10
	int duit; 
	string soal;
	int arrayopsi;
	int uang[15];
	char bantuan;
	string opsi[4];
	char jawab,jawaban_benar;
	int x=0,y=0,z=0;//Untuk Fungsi Bantuan
//algoritma
	srand(time(NULL));
	int pilih = rand() % 4 ;
	ifstream myfile; 
	switch (pilih){
		case 1 : myfile.open("one.txt"); break;
		case 2 : myfile.open("two.txt"); break;
		case 3 : myfile.open("three.txt"); break;
		case 4 : myfile.open("four.txt"); break;
		default : myfile.open("one.txt");break;
	}
	
	
	do{
		garis();
		cout<<"\t\t\t\t\t\tATTENTION !!"<<endl;
		cout<<"\t\t\tketik 'o' untuk menyerah , dan 'x' untuk opsi bantuan"<<endl;
		garis();
		cout<<endl<<endl;
		myfile >> uang[p];
		myfile.ignore(100,'\n');
		cout<<"\t\t\tSoal "<<p+1<<" Senilai Rp." << uang[p] <<endl;
		getline (myfile,soal);     
	    cout<<soal << endl;
		 
        myfile >> arrayopsi;   
        myfile.ignore(100,'\n');
        cout<<endl;
       	for(int i = 0; i < arrayopsi; i++)
		{
        getline(myfile,opsi[i]);
        cout  << opsi[i] <<  '\n';
        }
        
        myfile >> jawaban_benar;
        myfile.ignore(100, '\n');
      	
		go:
        cout << "Masukan Jawaban : ";
        cin >> jawab;
        cout<<endl;
        if (jawab==jawaban_benar)
		{
        	cout << "B E N A R ! "<<endl;
        	p++;
        	
		}else if(jawab=='o')
		{
			cout<<"Anda memilih menyerah."<<endl;
			cout<<"Anda membawa uang sebesar : Rp "<<uang[p-1];
			duit = uang[p-1];
			highscore(nama,duit);
			return 0;
		}else if(jawab=='x'){
        	char life;
    		if (x==1&&y==0&&z==0){
      			cout<<"\n 1.Aundience Poll \t\t 2.Call a Friend";
      			cout<<"\n Masukan Pilihan : ";
      			cin>>life;
      			switch (life) {
        		case '1':y=1;audiens(jawaban_benar);break;
        		case '2':z=1;telpon(jawaban_benar);break;
        		default : cout << "Pilihan Salah";break;
				}
				goto go;
 			}else if (y==1&&x==0&&z==0)
			{
      			cout<<"\n 1.50-50 \t\t 2.Call a Friend \t\t";
      			cout<<"\n Masukan Pilihan : ";
      			cin>>life;
      			switch (life) 
				{
        		case '1':x=1;fifty(opsi,jawaban_benar);break;
        		case '2':z=1;telpon(jawaban_benar);break;
        		default : cout << "Pilihan Salah";break;
				}
				goto go;
  			}else if (z==1&&x==0&&y==0){
      			cout<<"\n 1.50-50 \t\t 2.Aundience Poll \t\t";
      			cout<<"\n Masukan Pilihan : ";
      			cin>>life;
      			switch (life) {
        		case '1':x=1;fifty(opsi,jawaban_benar);break;
        		case '2':y=1;audiens(jawaban_benar);break;
        		default : cout << "Pilihan Salah";break;
				}
				goto go;
  			}else if ((x==1)&&(y==1)&&(z==0)){
      			cout<<"\n 1. Call A Friend";
      			cout<<"\n Masukan Pilihan : ";
      			cin>>life;
      			switch (life) {
        		case '1':z=1;telpon(jawaban_benar);break;
        		default : cout << "Pilihan Salah";break;
				}
				goto go;
  			}else if((x==1)&&(z==1)&&(y==0)){
      			cout<<"\n 1. Audience Poll";
      			cout<<"\n Masukan Pilihan : ";
      			cin>>life;
      			switch (life) {
        		case '1':y=1;audiens(jawaban_benar);break;
        		default : cout << "Pilihan Salah";break;
				}
				goto go;
  			}else if ((y==1)&&(z==1)&&(x==0)){
      			cout<<"\n 1. 50-50";
      			cout<<"\n Masukan Pilihan : ";
      			cin>>life;
      			switch (life) {
      			case '1': x=1;fifty(opsi,jawaban_benar);break;
       			default : cout << "Pilihan Salah";break;
				}
				goto go;
    		}else if ((x==0)&&(y==0)&&(z==0)) {
    			cout<<"\n 1.50-50 \t\t 2.Audience Poll \t\t 3.Call a Friend \t\t";
  				cout<<"\n Enter Choice : ";
  				cin>>life;
  				switch (life){
  				case '1': x=1;fifty(opsi,jawaban_benar);break;
  				case '2': y=1;audiens(jawaban_benar);break;
  				case '3': z=1;telpon(jawaban_benar);break;
  				default: cout<<"\n Error"<<endl;break;
				}
				goto go;
    		}if((x==1)&&(y==1)&&(z==1)) {
    			cout<<"\n anda tidak memiliki pilihan bantuan lagi"<<endl;
				goto go;
			}    	
		}else{
			cout << "\t\tS A L A H ! "<<endl;
			hadiah(p,nama);
			cout<<endl<<"Masih mau main ? (y/n)";
			cin>>main;
			if(main == 'n' )
			{
				return 0;
			}else if(main == 'y')
			{
				system("cls");
				goto _1M;
			}else{
				return 0;
			}
		}
		if(p==15)
        	{
        		hadiah(p,nama);
        		cout<<endl<<"Masih mau main ? (y/n)";
				cin>>main;
				if(main == 'n' )
				{
					return 0;
				}else
				{
					system("cls");
					goto _1M;
				}
			}
		system("pause");
		system("cls");
	}while (p<=15);
	myfile.close();
	
	return 0;
}
