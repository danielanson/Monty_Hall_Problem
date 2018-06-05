all:
	gcc -g -Wall monty_hall_problem.c -o monty_hall_problem
clean:
	rm -f ./monty_hall_problem
	rm -rf ./monty_hall_problem.dSYM
run:
	./monty_hall_problem
