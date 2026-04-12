from sys import stdin, stdout

def problema(a):
    if a >= 30:
        return "Yes"
    else:
        return "No"

def main():
    line = stdin.readline()
    parts = line.split()
    a = int(parts[0])
    stdout.write(problema(a))
main()