from sys import stdin,stdout

def main():
    line=stdin.readline()
    parts=line.split()
    a=int(parts[0])
    b=800*a
    c=int(a/15)*200
    stdout.write(str(int(b-c)))
main()