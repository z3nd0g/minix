# minix

Realizacja zadania polegającego na zmianie mechanizmu szeregowania procesów w systemie MINIX 2.03.

W systemie MINIX procesy są podzielone na trzy klasy: Task, Server i User. Procesy TASK maja priorytet nad procesami SERVER, a te nad procesami USER. Procedura szeregująca wybiera proces będący głową kolejki procesów gotowych.

W nowej realizacji procesy użytkowe USER dzielone są na trzy grupy A, B, C i każdej z tych grup może być przypisany kwant czasu procesora. Najpierw wybierany jest proces A, potem proces B, następnie proces C. Po wykorzystaniu swojego kwantu czasu, dany proces przesuwany jest na koniec kolejki procesów gotowych. 

Repozytorium zawiera pliki, które zostały zmodyfikowane w celu realizacji zadania. Pliki o rozszerzeniu .old to oryginalne pliki Minixa.
