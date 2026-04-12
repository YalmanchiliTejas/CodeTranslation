import sys
input = sys.stdin.readline

def main():
    s=list(input())
    a,b=0,0
    for i in range(3):
        if s[i]=='A':
            a+=1
        else:
            b+=1
    if a*b==0:
        print('No')
    else:
        print('Yes')

if __name__ == '__main__':
    main()