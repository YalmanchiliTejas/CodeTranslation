from sys import stdin,stdout

def main():
    line=stdin.readline()
    parts=line.split()
    a=int(parts[0])
    if a>=30:
        stdout.write("Yes")
    else:
        stdout.write("No")
main()