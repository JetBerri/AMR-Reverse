# AMR-Reverse
Reverse shell for linux and Windows written in C and AMR.

# Use 

For compiling the c script you have to run:
```
$ gcc main.c - o main
```
For running it:
```
$ ./main
```

If you wanna compile the Assembly code you can run:
```
$ as amr-reverse.s -o amr-reverse.o && ld -N amr-reverse.o -o amr-reverse
```
And for running:
```
$ ./amr-reverse
```

# Use of it

For using this tool you have to at least have some assembly knowledge, the victim should run netcat in the port that you have chosen to enable the remote shell.
You can add a simple shell script (.sh) with social engineenering to make the victim run it.

# Disclaimer

I'm not responsable of the uses of this tool. Thanks for using.
