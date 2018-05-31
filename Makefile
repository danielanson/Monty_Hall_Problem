all:
	gcc -g -Wall monty_hall_problem.c -o monty_hall_problem
clean:
	rm -f ./monty_hall_problem
run:
	./monty_hall_problem
