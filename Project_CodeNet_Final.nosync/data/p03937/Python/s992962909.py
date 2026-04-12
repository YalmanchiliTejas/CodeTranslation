import bisect,collections,copy,itertools,math,string
import sys
def I(): return int(sys.stdin.readline().rstrip())
def LI(): return list(map(int,sys.stdin.readline().rstrip().split()))
def S(): return sys.stdin.readline().rstrip()
def LS(): return list(sys.stdin.readline().rstrip().split())
def main():
    h,w = LI()
    shortest = h+w-1
    cnt = 0
    for i in range(h):
        line = S()
        cnt += line.count("#")
    ans = shortest==cnt 
    print("Possible" if ans else "Impossible")
main()            
