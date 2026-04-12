from sys import stdin
def main():
    readline=stdin.readline
    s=readline().strip()
    flagA=False
    flagB=False
    for i in range(len(s)):
        if s[i]=="A":
            flagA=True
        else:
            flagB=True
    if flagA and flagB:
        print("Yes")
    else:
        print("No")

if __name__=="__main__":
    main()