import sys
from collections import deque

dic={'o':lambda s:1-(s[1]^s[0]), 'x':lambda s:s[1]^s[0]}
def mknseq(ox,ld):
    for x in ld:
        x.append(dic[ox]([x[-2],x[-1]]))
def main():
    N=int(sys.stdin.readline().strip())
    s=list(sys.stdin.readline().strip())
    ans=[deque([x,y]) for x in range(2) for y in range(2)]
    for x in range(N):
        mknseq(s[x],ans)
    ans=[list(x) for x in ans]
    # print(ans)
    for x in ans:
        if x[:2]==x[-2:]:
            return print(''.join([['W','S'][i] for i in x[1:-1]]))
    print(-1)

if __name__=='__main__':
    main()
