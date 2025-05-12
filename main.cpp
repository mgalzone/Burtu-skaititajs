#include <iostream> // ievades/izvades funkcijaam (cout, cin)
#include <vector> // ieklauj vektorus
#include <string> // ieklauj string
#include <algorithm> // ieklauj, piemeram, burtu sakartosanu pec visbiezak izmantotaa
#include <map> // ieklauj, piemeram, funkciju, kas saskaita katra burta biezhumu tekstaa

using namespace std; // lai nav katru reizi jaraksta std:: pirms funkcijam

//funkcija, kas skaita patskanus, lidzskanus un atstarpes dotajaa teikumaa
void skaititlidzskanusunpatskanus(const string& teikums, int& patskani, int& lidzskani, int& atstarpes) {
//sakumaa visus 3 iestata uz 0
    patskani = 0;
    lidzskani = 0;
    atstarpes = 0;

    for (char burts : teikums) { // parbauda, vai ievaditais ir burts, tad darbojas talak
        if (isalpha(burts)) { // parbauda, vai ievaditais ir burts (nav cipars/cits simbols)
            // parbauda, vai tas ir patskanis
            if (burts == 'a' || burts == 'e' || burts == 'i' || burts == 'o' || burts == 'u' ||
                burts == 'A' || burts == 'E' || burts == 'I' || burts == 'O' || burts == 'U') {
                ++patskani; // ja ir, tad palielina patskanu skaitu par vienu
            } else {
                ++lidzskani; // ja nav, tad palielina lidzskanu skaitu par vienu
            }
        } else if (burts == ' ') {
// ja simbols ir atstarpe, palielina atstarpju skaitu par vienu
            ++atstarpes; // pieskaita vienu atstarpi
        }
    }
}


// spele, kur jasakarto burti pareiza seciba
void sajauktievardi() {
    const int a = 10; // vardu skaits
    string vards[a] = {
        "banquet", "whistle", "journey", "fragile", "velvet", "harvest", "adventure", "glimpse", "satisfaction", "sincere"
    };

    string sajauktaisvards[a] = {
        "baqtune", "whleist", "eynjrou", "glfraei", "tvveel", "tsrahve", "advurtnee", "pscmilge", "saftcinatiso", "eernisc"
    };

    string j; // mainiigais, lai lietotajs varetu ievadit savu atbildi
    int score = 0; // rezultats sakumaa ir 0

    cout << "Sakaarto burtus pareizaa seciibaa!" << endl;

    for(int i = 0; i < a; i++) {
        cout << "\nSajauktais vards: " << sajauktaisvards[i] << endl; // paradas sajauktais vards
        cin >> j;
        if(j == vards[i]) { // salidzina atbildi ar pareizo vardu
            cout << "Apsveicu!" << endl; // ja ir pareizi
            score++;
        } else {
            cout << "Nepareizi. Pareizaa atbilde: " << vards[i] << endl; //ja nav
        }
    }

    cout << "\nTavs rezultaats: " << score << " no " << a << " pareiziem." << endl;
}

// spele – saskaiti sava teikuma patskanus un lidzskanus
void pirmaaspele() {
    string teikums; //mainigais, kas bus lietotaja ievaditais teikums
    cout << "Spele: straadaa ar savu teikumu" << endl;
    cout << "Ievadi garu teikumu: ";
    getline(cin, teikums); // iegust teikumu

    int patskani = 0, lidzskani = 0, atstarpes = 0; //sakuma to skaits ir 0

    skaititlidzskanusunpatskanus(teikums, patskani, lidzskani, atstarpes);  // izsauc funkciju, kas tos saskaita
    int minetiepatskani, minetielidzskani; // mainigie, kuros lietotajs ievadis savu atbildi
    cout << "Nosaki, cik patskanu ir teikumaa: ";
    cin >> minetiepatskani;

    cout << "Nosaki, cik lidzskanu ir teikumaa: ";
    cin >> minetielidzskani;

    if (minetiepatskani == patskani && minetielidzskani == lidzskani) //salidzina
        cout << "Pareizi!" << endl; // ja abas atbildes ir pareizas
    else {
        cout << "Nepareizi." << endl; // ja nav
        cout << "Pareizi: " << patskani << " patskani un " << lidzskani << " lidzskani." << endl;
    }
}


// paskaidrojums par katru valodas kludu
void skaidrojums(int indekss) {
    vector<string> paskaidrojumi = {
        // paskaidrojumi par katru kludu

        "*would* nevar izmantot *if* dalaa",
        "*which* nevar izmantot, kad runa par cilvekiem – jalieto *who*",
        "ar vardu *married* jaizmanto *to*, nevis *with*",
        "ja pat *team* norada, ka tajaa ir vairaki cilveki, jaiznoto *is*, jo *team* ir tikai viena",
        "nepareiza pagatnes forma, pec *has* jaalieto *gone*, nevis *went*",
        "nepareiza vardu seciba – ja butu tikai *what time is it?*, tad butu pareizi",
        "taa nedrikst, jo sanak *double negatives* viena teikumaa",
        "*their* jaizmanto citaa nozimee – jasaka *they are* jeb *they’re*",
        "iespejamas situacijas, jaiznoto *were*, nevis *was*",
        "atkartotam darbibaam jaiznoto *present perfect* - *has sung*, nevis *sang*",
        "*its* sajaa teikumaa ir nozime *it is*, tapec saisinajumaa tas butu *it’s*",
        "nedrikst lietot *more* pirms *kinder*, jo *kinder* jau ir paraakaa forma",
        "*whom* jaiznoto citaa nozimee",
        "*each* noraada, ka jaizmanto vards vienskaitli (*has*), ja pat vinu ir vairak",
        "*suggested me* – pec *suggested* lieto *that I go*, nevis *me*",
        "*less people* – ja runa par saskaitamiem lietvardiem, jasaka *fewer*",
        "*borrow me* nav pareizi – ja ir vajadziba kaut ko sanemt, lieto *lend*",
        "*used to* lieto citaa nozimee",
        "*environment* raksta ar *n*",
        "*acquaintances* raksta ar *a*"
    };
    cout << "Paskaidrojums: " << paskaidrojumi[indekss] << endl;
}
void kludas() {
    vector<string> kludaini = { // teikumi ar kludam
        "If I would have known, I would have helped.",
        "The man which helped you is my brother.",
        "She is married with a lawyer.",
        "The team are winning the match.",
        "He has went to the store.",
        "Do you know what time is it?",
        "I don’t know nothing.",
        "Their going to the concert tonight.",
        "If I was you, I wouldn’t do that.",
        "She sang that song many times before.",
        "Its a beautiful day outside.",
        "She was more kinder than before.",
        "Whom is knocking at the door?",
        "Each of the students have a book.",
        "He suggested me to go there.",
        "There are less people at the event.",
        "Can you borrow me your pen?",
        "I didn't used to like coffee.",
        "He seems to like this enviroment.",
        "She has many acquaintences."
    };
// pareizie teikumi
    vector<string> pareizie = {
        "If I had known, I would have helped.",
        "The man who helped you is my brother.",
        "She is married to a lawyer.",
        "The team is winning the match.",
        "He has gone to the store.",
        "Do you know what time it is?",
        "I don’t know anything.",
        "They’re going to the concert tonight.",
        "If I were you, I wouldn’t do that.",
        "She has sung that song many times before.",
        "It's a beautiful day outside.",
        "She was kinder than before.",
        "Who is knocking at the door?",
        "Each of the students has a book.",
        "He suggested that I go there.",
        "There are fewer people at the event.",
        "Can you lend me your pen?",
        "I didn't use to like coffee.",
        "He seems to like this environment.",
        "She has many acquaintances."
    };

    int score = 0; // mainigais, kas skaita pareizo atbilzu skaitu

    for (int i = 0; i < kludaini.size(); ++i) {
        string atbilde; // mainigais, kuraa lietotajs ievadis atbildi
        cout << "\nAtrodi kludu saja teikumaa (ievadi laboto versiju):\n";
        cout << "-> Teikums: " << kludaini[i] << endl;
        cout << "Izlabotais teikums: ";
        getline(cin, atbilde); // iegust lietotaja labojumu

        if (atbilde == pareizie[i]) { //salidzina lietotaja atbildi ar pareizo
            cout << "Pareizi!\n"; //ja atbilde ir pareiza
            ++score;
        } else {
            cout << "Nepareizi – pareizais teikums ir:\n";
            cout << "\"" << pareizie[i] << "\"\n"; // parada pareizo teikumu
            skaidrojums(i); // izsauc, lai izskaidrotu kludu nepareizajaa
        }
    }

    cout << "\nTu pareizi atbildeji uz " << score << " no " << kludaini.size() << " jautajumiem.\n";
}
// galvena funkcija, kas izsauc visas speles
int main() {
    string teikums; // mainigais, kura lietotajs ievadis tekstu
    cout << "Ievads: ievadi garaku tekstu, kam velies noteikt patskanu, lidzskanu skaitu u.c.: ";
    getline(cin, teikums); // iegust ievadito teksts

//mainigie, kas saskaitis visus tris
    int patskani = 0, lidzskani = 0, atstarpes = 0;

// izsauc funkciju, kas skaita visus 3
    skaititlidzskanusunpatskanus (teikums, patskani, lidzskani, atstarpes);

// izprinte rezultatu
    cout << "Patskani: " << patskani << endl;
    cout << "Lidzskani: " << lidzskani << endl;
    cout << "Burti kopaa: " << (patskani + lidzskani) << endl;
    cout << "Atstarpes: " << atstarpes << endl;

    // visbiezaka burta noteiksana

    map<char, int> burtiCount; //saglabas katra burta biezhumu
    for (char c : teikums) { //iziet cauri katrai zimei teikumaa
        if (isalpha(c)) { //ja zime ir burts
            burtiCount[tolower(c)]++; // palielina konkretaa burta biezhumu
        }
    }

// mainigie visbiezhakaa burta noskaidrosanai
    char visbiezakaisburts;
    int burtuskaits = 0;

//atrod visbiezhako burtu
    for (auto& b : burtiCount) {
        if (b.second > burtuskaits) { // ja sis burts tiek lietots vairak, neka ieprieksejais
            burtuskaits = b.second;
            visbiezakaisburts = b.first; // saglabaa so burtu
        }
    }

    cout << "Visbiezak lietotais burts: '" << visbiezakaisburts << "' - " << burtuskaits << " reizes.\n";

    // burtu sakartosana pec lietojuma biezhuma
    vector<pair<char, int>> sakartotiBurti(burtiCount.begin(), burtiCount.end());
    sort(sakartotiBurti.begin(), sakartotiBurti.end(), [](const pair<char, int>& a, const pair<char, int>& b) {
// karto pec biezhuma – no visbiezakaa lîdz visretakajam
// ja biezhums ir vienads, karto alfabeta secibaa
        return a.second == b.second ? a.first < b.first : a.second > b.second;
    });

    cout << "Burtu lietojuma biezums (no visbiezaak lidz visretaak lietotajam):" << endl;
    for (const auto& par : sakartotiBurti) {
        cout << "'" << par.first << "' - " << par.second << " reizes\n";
    }
//izsauc speles funkcijas
    pirmaaspele(); // izsauc teikuma speeli
    kludas(); // izsauc kludu labosanas speeli
    sajauktievardi(); // izsauc sajaukto vardu speeli

    return 0; //beidz programmu
}

