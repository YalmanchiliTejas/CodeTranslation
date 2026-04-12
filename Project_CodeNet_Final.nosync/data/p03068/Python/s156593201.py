import sys

def solve(N, S, K):
    char = S[K-1]

    ans = ''
    for i in xrange(len(S)):
        ans += S[i] if S[i] == char else '*'
    return ans

if __name__ == '__main__':

    N = sys.stdin.readline().strip()
    S = sys.stdin.readline().strip()
    K = sys.stdin.readline().strip()
    ans = solve(int(N), S, int(K))
    print ans