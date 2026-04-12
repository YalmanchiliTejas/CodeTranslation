import sys
def S(): return sys.stdin.readline().rstrip()
def IL(): return map(int,sys.stdin.readline().rstrip().split())

if __name__=='__main__':
    h,w = IL()
    m = [S() for _ in range(h)]
    for i in range(h):
        for j in range(w):
            if i==h-1 or j==w-1:
                continue
            if m[i][j+1]=='#' and m[i+1][j]=='#':
                print('Impossible')
                exit()
    print('Possible')
    exit()