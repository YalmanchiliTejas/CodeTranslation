from sys import stdin, stdout

def main():
    line = stdin.readline()
    parts = line.split()
    x = int(parts[0])
    stdout.write('Yes' if x>=30 else 'No')

main()