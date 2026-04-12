from sys import stdin, stdout


def main():
    line = stdin.readline()
    parts = line.split()
    n = int(parts[0])
    x = 800*n
    y = (int(n/15)) * 200



    stdout.write( str(x-y))


main()
