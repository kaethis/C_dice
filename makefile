dice: dice.o
	g++ dice.o -g -o dice

dice.o: dice.cpp
	g++ -g -c dice.cpp

clean:
	rm *.o dice

archive:
	
