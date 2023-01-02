#include<iostream>
using namespace std;

class publication{
    protected:
            string title;
            float price;
    public:
            void get_data();
            void put_data();
            publication(){
                title="";
                price=0;
            }

};

class book : public publication
{
        private :
                int pagecount;
        public :
                void get_book_data();
                void put_book_data();
                book()
                {
                        pagecount = 0;
                }
};

class tape : public publication
{
        private :
                float playtime;
        public :
                void get_tape_data();
                void put_tape_data();
                tape()
                {
                        playtime = 0;
                 }
};

void publication::get_data(){
    cout<<"enter title:";
    getline(cin,title);
    cout<<"enter price:";
    cin>>price;

}

void publication::put_data(){
    cout<<"\n******title,price is:********\n";
    cout<<"title:"<<title<<endl;

    try{
        if (price<0){
            throw(5);

        }
    }
    catch(int y){
        cout<<"price not valid!!"<<endl;
        price=0;
        

    }
    cout<<"price:"<<price<<endl;
    
}

void book::get_book_data(){
    cout<<"enter pagecount:";
    cin>>pagecount;
}

void book::put_book_data(){
    cout<<"\n******title,priceand page count is:********\n";
    cout<<"Title: "<<title<<endl;
    cout<<"Price: "<<price<<endl;
    cout<<"pagecount: "<<pagecount<<endl;
    cout<<"            ********            "<<endl;

}

void tape::get_tape_data(){
    cout<<"Title:";
    cin>>title;
    cout<<"enter play time:";
    cin>>playtime;

}

void tape::put_tape_data(){
    cout<<"\n******title and playtimet is:********\n";
    cout<<"title:"<<title<<endl;
    try{
        if (playtime<0){
            throw(5);
        }
    }
    catch(int z){
        cout<<"playtime cannot be zero"<<endl;
        playtime=0;
        
        
    }
    cout<<"playtime is:"<<playtime<<endl;
    cout<<"******"<<endl;
}

int main(){
    book b;
    tape t;
    b.get_data();
    b.put_data();
    b.get_book_data();
    b.put_book_data();
    
    t.get_tape_data();
    
    
    
    
    
    
    
    t.put_tape_data();
    return 0;
}