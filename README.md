# Million-digit Fibonacci in C

### Currey Adkins challenge 2017

Generate a million-digit Fibonacci number using only addition and subtraction in c.

- Generate `N-th` Fibonacci number and write to a file `nthFibonacci`.

- `N` is a positive integer up to a number for which the result is a million digit Fibonacci.
- The first couple of fibonacci numbers are `1 2`

- Only allowed mathmetical operations are addition and subtraction.

- No precomputation allowed.

### How to run

- Source code: `fibo.c`
- Compile `gcc -O3 fibo.c -o fibo.out`
- Run `/fibo.out 8` . It will generate 8th Fibonacci number.
- This `/fibo.out 5000000` generates a Fibonacci number of `1,044,939` digits.

### Bragging

I won the challenge and Currey@Adkins was generous to give me a prize money of \$1000 and an award.

![Award](award.jpg)

### How did you optimize to make it faster than other solutions?

- I did add two numbers in base `1e19` and stored fibonacci number in an array of `long long int`.
