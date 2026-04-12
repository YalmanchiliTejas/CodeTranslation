import sys
def input(): return sys.stdin.readline().strip()

def resolve():
    h,w=map(int, input().split())
    l=[]
    for i in range(h):
        ll=list(input())
        l.append(ll)
    # 行と列のチェックリストを作る。gyou[0]は0行目を示す
    gyou= [False] * w
    retu= [False] * h
    for jretu in range(h):
        for kgyou in range(w):
            # 同じ行or列に１個でも'#'があればその時点でその行or列は消えない
            # '#'があった列と行をTrueにしていく
            if l[jretu][kgyou]=='#':
                retu[jretu]=True
                gyou[kgyou]=True
    for jretu in range(h):
        if retu[jretu]:
            for kgyou in range(w):
                if gyou[kgyou]:
                    print(l[jretu][kgyou],end='')
            print('')
resolve()