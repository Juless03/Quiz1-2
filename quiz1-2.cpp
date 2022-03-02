/* ITCR. Ing.Computación.
   Análisis de algoritmos. GR 1
   Quiz #1 y #2. 
   Autora: Juleisy Porras Diaz 2021123254
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Noticia{     //clase madre
    private:
        string title;
        string date;
        string journalist;
    public:
        Noticia(string, string, string);  //constructor
        virtual ~Noticia();
        virtual void getInfo();
};

class NoticiaPaper : public Noticia{  //clase hija, hereda de noticia
    private:
        string path; //debe agregar una ruta a un archivo (foto de la noticia)
    public:
        NoticiaPaper(string, string, string, string);
        void getInfo();
};

class NoticiaDigital : public Noticia{ //clase hija, hereda de noticia
    private:
        string media; //tiene una lista de diversos tipos de media(video, audio, fotos)
    public:
        NoticiaDigital(string, string, string, string);
        void getInfo();
};

class NoticiaRadio : public Noticia{  //clase hija, hereda de noticia
    private:
        string audioUrl; //posee un url a un audio file
    public:
        NoticiaRadio(string, string, string, string);
        void getInfo();
};

Noticia::Noticia(string _title, string _date, string _journalist){
    title = _title;
    date = _date;
    journalist = _journalist;
}

Noticia::~Noticia(){   
}

NoticiaPaper::NoticiaPaper(string _title, string _date, string _journalist, string _path) : Noticia (_title, _date, _journalist){
    path = _path;
}

NoticiaDigital::NoticiaDigital(string _title, string _date, string _journalist, string _media) : Noticia (_title, _date, _journalist){
    media = _media;
}

NoticiaRadio::NoticiaRadio(string _title, string _date, string _journalist, string _audioUrl) : Noticia (_title, _date, _journalist){
    audioUrl = _audioUrl;
}

void Noticia::getInfo(){
    //retorna la info de la clase madre
    cout << "Titulo: " << title << endl;
    cout << "Fecha:  " << date << endl;
    cout << "Reportero: " << journalist << endl;
}

void NoticiaPaper::getInfo(){
    Noticia::getInfo();
    cout << "Ruta al archivo: " << path << endl;
}

void NoticiaDigital::getInfo(){
    Noticia::getInfo();
    cout << "Media: " << media << endl;
}

void NoticiaRadio::getInfo(){
    Noticia::getInfo();
    cout << "Url a un archivo de audio: " << audioUrl << endl;
}

int main(){

    /*hacer un vector de tipo Noticia con cada instancia de cada clase hija,
    hacer un for que recorra el vector y por polimorfismo invocar al metodo getInfo de
    las clases hijas, constatando que imprimen los datos de Noticia y un algo más
    dependiendo de la implementación en la clase hija
    */

    vector<Noticia*> news;

    NoticiaPaper* n1 = new NoticiaPaper("Terremoto", "12 de febrero", "Juleisy Porras", "Foto");
    NoticiaDigital* n2 = new NoticiaDigital("Avalancha", "02 de marzo", "Juleisy Porras", "Archivo");
    NoticiaRadio* n3 = new NoticiaRadio("Robo a mano armada", "6 de diciembre", "Juleisy Porras", "https://www.youtube.com/watch?v=k1-TrAvp_xs");

    news.push_back(n1);
    news.push_back(n2);
    news.push_back(n3);

    for(int i = 0; i < news.size(); i++){
        news[i]->getInfo();
        cout << endl;
    }

    delete n1;
    delete n2;
    delete n3;

    return 0;
}