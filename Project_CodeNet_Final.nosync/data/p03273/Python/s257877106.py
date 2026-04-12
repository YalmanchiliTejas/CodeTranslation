import sys
def input(): return sys.stdin.readline().strip()

def resolve():
    h,w=map(int, input().split())
    l=[]
    for i in range(h):
        ll=list(input())
        l.append(ll)
    # lはl[列番号][行番号]になってる
    # 行と列のチェックリストを作る。行が縦で列が横
    gyou= [False] * w
    retu= [False] * h
    # 列番号をずらしていく
    for retunum in range(h):
        # 行番号をずらしていく
        for gyounum in range(w):
            # 同じ行or列に１個でも'#'があればその時点でその行or列は消えない
            # '#'があった列と行をTrueにしていく
            if l[retunum][gyounum]=='#':
                retu[retunum]=True
                gyou[gyounum]=True
    # 列も行もTrue→行と列の両方のどこかに'#'があるから、行と列の交点のマスは消えない
    for retunum in range(h):
        if retu[retunum]:
            for gyounum in range(w):
                if gyou[gyounum]:
                    # 同じ列の出力が終わるまでは改行しない
                    print(l[retunum][gyounum],end='')
            # １個の列が終わったら改行
            print('')
resolve()