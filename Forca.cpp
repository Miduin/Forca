#include <iostream>
#include <stdlib.h>
#include "lib/body.h"

#ifdef WIN32
#define CLEAR_COMMAND "cls"
#else
#define CLEAR_COMMAND "clear"
#endif

#define MAX_LIFE 6

using namespace std;

int main() {
    char pl[25], lt[1], sc[25];
    int cc = MAX_LIFE;
    int sz = 0;
    int a = 0;
    int ac = 0;

    cout << "oi, bem vindo ao jogo da forca!\n"
         << "peca para alguem digitar uma palavra para voce descobrir...\n";
    cin >> pl;

    system(CLEAR_COMMAND);

    cout << "\nvamos dar inicio!\n";
    while (pl[a] != '\0') {
        a++;
        sz++;
    }

    print_body();

    for (a = 0; a < sz; a++) {
        sc[a] = '_';
    }

    while (cc > 0 && ac < sz) {
        cout << "jogadas restantes: " << cc << "\n\n";
        cout << "Palavra sec.: ";

        for (a = 0; a < sz; a++) {
            cout << sc[a];
        }

        cout << "\nDigite uma palavra: ";
        cin >> lt[0];

        bool exists = false;

        for (a = 0; a < sz; a++) {
            if (pl[a] == lt[0] && sc[a] == '_') {
                exists = true;
                sc[a] = lt[0];
                ac++;
            }
        }

        if (!exists) {
            remove_part();
            cc--;
        }

        system(CLEAR_COMMAND);
        print_body();
    }

    if (ac == sz) {
        cout << "\nparabens, voce ganhou!\n";
    } else {
        cout << "\nops, que pena...\n";
    }

    return 0;
}
