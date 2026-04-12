from sys import stdin
def main():
    #入力
    readline=stdin.readline
    S=readline().strip()
    if S=="AAA" or S=="BBB":
        print("No")
    else:
        print("Yes")
if __name__=="__main__":
    main()