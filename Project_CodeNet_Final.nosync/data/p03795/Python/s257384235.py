from sys import stdin, stdout

def main():
    line = stdin.readline()
    parts = line.split()
    X = int(parts[0])
    x = X*800
    y = 200*int(X/15)
    stdout.write(str(x-y))

main()