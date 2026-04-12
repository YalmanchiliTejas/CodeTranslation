from sys import stdin, stdout


def main():
    line = stdin.readline()
    parts = line.split()
    a = int(parts[0])
    rta = "No"
    if a >= 30:
        rta = "Yes"

    stdout.write(rta)


main()