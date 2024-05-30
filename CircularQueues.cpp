#include <iostream>
using namespace std;

class Queues {
    private:
    static const int max = 3;
    int FRONT, REAR;
    int queue_array[max];

    public:
    Queues() {
        FRONT = -1;
        REAR = -1;
    }

    void insert() {
        int num;
        cout << "Enter a number:";
        cin >> num;
        cout << endl;

        if ((FRONT == 0 && REAR == max - 1) || (FRONT == REAR + 1)) {
            cout << "\nQueue overflow\n";
            return;
        }

        if (FRONT == -1) {
            FRONT = 0;
            REAR = 0;
        }
        else {
            if (
                REAR == max - 1)
                REAR = 0;
            else
            REAR = REAR + 1;
        }
        queue_array[REAR] = num;
    }

    void remove() {
        // cek apakah antrian kosong
        if (FRONT == -1) {
            cout << "Queue underflow\n";
            return;
        }
        cout << "\nThe element deleted from the queue is:" << queue_array[FRONT] <<"\n";

        //cek jika antrian hanya memiliki satu element
        if (FRONT == REAR) {
            FRONT = -1;
            REAR = -1;
        }
        else {
            //jika element yg dihapus berada di posisi terakir array, kembali ke awal array
            if(FRONT == max - 1)
            FRONT = 0;
            else
            FRONT = + 1;

        }
    }

    void display() {
        int FRONT_Position = FRONT;
        int REAR_Position = REAR;

        // cek apakah antrian kosong
        if (FRONT_Position == -1) {
            cout << "Queue is empty\n";
            return;
        }

        cout << "\nElements in the queue are...\n";

        //jika FRONT <= REAR, iterasi dari FRONT hingga REAR
        if (FRONT_Position <= REAR_Position) {
            while (FRONT_Position <= REAR_Position) {
                cout << queue_array [FRONT_Position] << "  ";
                FRONT_Position++;
            }
            cout << endl;
        }    
        else{
                        //Iterasi dari awal array hingga REAR
            while (FRONT_Position <= REAR_Position) {
                cout << queue_array[FRONT_Position] << "  "; 
                    FRONT_Position++;               
            }

            FRONT_Position = 0;

            //iterai dari awal array hingga REAR
            while (FRONT_Position <= REAR_Position) {
                cout << queue_array[FRONT_Position] << "   ";
                FRONT_Position++;
            }

        }

};