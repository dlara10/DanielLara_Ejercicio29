plot.png: onda.dat plot.py
	python plot.py

%.dat : a.out
	./a.out 

a.out: DanielLara_Ejercicio29.cpp
	g++ DanielLara_ejercicio29.cpp

clean:
	rm -rf a.out onda.dat plot.png *~