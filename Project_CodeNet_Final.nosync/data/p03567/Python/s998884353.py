from sys import stdin

def readString() :
    return  stdin.readline().rstrip()

def solve() :
    S = readString()
    pos = S.find('AC')
    if(pos!=-1):
        print("Yes")
    else :
        print("No")
solve()