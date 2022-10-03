#include<iostream>
#include<string.h> // mengenali strlvr(str)

using namespace std;

struct cinema_schedule{ // struct jadwal bioskop
	string movie_title;
	string main_character;
	string show_date;
	string genre;
	int duration;
};

cinema_schedule schedule[50]; // memanggil struct 

cinema_schedule Schedule;
cinema_schedule* ptrSchedule = &Schedule;

int many_movie = 0; // meanmpung banyak data film
char name[100];

void tagline(){
	cout<< "\n____APLIKASI JADWAL FILM BIOSKOP____"<< endl; // tagline program
}

void show_menu(){ // menu program
    cout<< "\n----------------------------" << endl
    	<< "|       MENU PENDATAAN      |" << endl // memiliki 5 operasi
    	<< "----------------------------" << endl
        << "1. Tambah Data" << endl
        << "2. Lihat Data" << endl
        << "3. Ubah Data" << endl
        << "4. Hapus Data" << endl
        << "5. Exit" << endl
        << "----------------------------" << endl;
}

void add_data(){ // menambah data film
	int i = many_movie;
	int array = 50;
	
	if(i < array){ // banyak data harus kurang dari 100
	  	cout<< "\n--------INPUT JADWAL FILM BIOSKOP--------"<< endl;
	  	
		cout<< "Judul Film         : "; fflush(stdin);
		getline(cin, ptrSchedule->movie_title); //memanggil field struct dengan pointer
		
		cout<< "Karakter Utama     : "; fflush(stdin);
		getline(cin, ptrSchedule->main_character);
		
		cout<< "Genre Film         : "; fflush(stdin);
		getline(cin, ptrSchedule->genre);
		
		cout<< "Tanggal Tayang     : "; fflush(stdin);
		getline(cin, ptrSchedule->show_date);
	    
	    cout<< "Durasi             : "; cin >> ptrSchedule->duration;  
	    
	    schedule[many_movie] = Schedule;
	    many_movie++;
	    
		cout<<"\n---DATA BERHASIL DITAMBAHKAN---\n";
	}	
	
	else{
		cout<< "ARRAY DATA HANYA 100!" << endl; 
	}
}

void show_data(){ // menampilkan jadwal film bioskop
	cout<< "\n----------DAFTAR JADWAL FILM BIOSKOP----------";
	int i = many_movie;

	
	if (i > 0){ // banyak data lebih dari 0
		for(int i = 0; i < many_movie; i++){ // akan tampil sebanyak jumlah film
		
			cinema_schedule Schedule = schedule[i];
			cinema_schedule* ptrSchedule = &Schedule;
			
		  	cout<<"\n\n----------FILM KE - " << i + 1 << "----------";
			cout<< "\nJudul Film         : " << ptrSchedule->movie_title;
			 
			cout<< "\nKarakter Utama     : " << ptrSchedule->main_character;

			cout<< "\nGenre Film         : " << ptrSchedule->genre;
			
			cout<< "\nJadwal Tayang      : " << ptrSchedule->show_date;
			
		    cout<< "\nDurasi             : " << ptrSchedule->duration << " Menit" << endl;
	
		}
	}
	else {
		cout<< "\n---Daftar Jadwal Film Kosong---!" << endl; // jadwal kosong jika banyak data < 0
	}
}

void update_data(){ // Mengubah jadwal film
	int i = 0, update_number;
	if (i < many_movie){ 
		
		show_data(); // menampilkan data film
		
		cout<< "\n\n--------UPDATE JADWAL FILM BIOSKOP--------"<< endl;
		
		
		cout << "Pilih Data Yang Ingin Diubah: "; cin >>  update_number; // nomor film yang mau diuah
		
		update_number = update_number-1;
		
		system("cls");
		
		Schedule = schedule[update_number];
		
		cout<< "\n--------INPUT JADWAL FILM BIOSKOP--------"<< endl;
	  	
		cout<< "Judul Film         : "; fflush(stdin);
		getline(cin, ptrSchedule->movie_title);
		
		cout<< "Karakter Utama     : "; fflush(stdin);
		getline(cin, ptrSchedule->main_character);
		
		cout<< "Genre Film         : "; fflush(stdin);
		getline(cin, ptrSchedule->genre);
		
		cout<< "Tanggal Tayang     : "; fflush(stdin);
		getline(cin, ptrSchedule->show_date);
	    
	    cout<< "Durasi             : "; cin >> ptrSchedule->duration;  
	    
	    schedule[update_number] = Schedule;
	    
		cout<<"\n---DATA BERHASIL DIUBAH---\n";
	}	
	
	else {
		cout<< "\n---Daftar Jadwal Film Kosong---!" << endl; // jadwal kosong jika banyak data < 0
	}
}

clear_data(){ // menghapus data film
	int i = 0, delete_number;
	if (i < many_movie){	
	
		show_data(); // menampilkan data
		
		cout<< "\n\n--------MENGHAPUS JADWAL FILM BIOSKOP--------"<< endl;
		cout << "Film berapa yang ingin dihapus : "; cin >>  delete_number; // nomor film yang ingin dihapus
		
		system("cls");
		
		for (int i = 0; i < many_movie; i++) {
          if(i < delete_number) {
            schedule[i] = schedule[i];
          }
          if(i > many_movie) {
            schedule[i - 1] = schedule[i];
          }
        }
        many_movie--;
		cout<< "\n---DATA BERHASIL DIHAPUS--"<< endl;
	}
	
	else {
		cout<< "\n---Daftar Jadwal Film Kosong---!" << endl; // jadwal kosong jika banyak data < 0
	}
}

void exit_program(){ // keluar dari program
	cout<< "\nTERIMA KASIH TELAH MENGGUNAKAN PROGRAM INI " << name << "   >.<" << endl;
}

int main(){
	int choose;
	char again;
	
	cout<< "\n>>> INPUT NAMA UNTUK MASUK KE PRORGAM <<<" << endl; // login
	cout<< "Masukkan Nama Anda : "; gets(name); 
	strupr(name); // mengubah huruf kecil jadi kapital
	system("cls"); // membersihkan output sebelumnya
	
	cout<< "\n----------------------------------------------" << endl
		<< "SELAMAT DATANG " << name << "   >.<" << endl
		<< "----------------------------------------------" << endl;
	
	back :
	tagline();
	show_menu();
		cout<< "\nPilih Menu : ";  cin >> choose; 
		system("cls");
		if(choose == 1){
			add_more : // blok
				add_data();
				cout<< "\nApakah ingin menambah film lagi? (y/n) : "; cin >> again ; 
				system("cls");
				if (again == 'y' || again == 'Y'){
					goto add_more; // pergi ke blok add_more
					cout<< endl; 
				}
				
				else{
				     main(); // pergi ke blok start program
				}
		}
		
		else if(choose == 2){
			show_data();
			goto back;
		}
		
		else if(choose == 3){
			update_again : 
				update_data(); // memanggil prosedur
				cout<< "\nApakah ingin mengubah film lagi? (y/n) : "; cin >> again ;
				system("cls");
				if (again == 'y' || again == 'Y'){
					goto update_again;
					cout<< endl;
				}
				
				else{
				    main();
				}
		}
		
		else if(choose == 4){
			delete_again :
				clear_data();
				cout<< "\nApakah ingin menghapus film lagi? (y/n) : "; cin >> again ;
				system("cls");
				if(again == 'y' || again == 'Y'){
					goto delete_again;
					cout<< endl;
				}
				
				else{
				    main();
				}
		}
		
		else if(choose == 5){
			exit_program();
		}
		
		else {
			system("cls");
			cout << "Pilihan Menu Tidak Tersedia!" << endl; // pilihan diluar 1 sampai 5
			main();
		}
				
}	
