import sys
from collections import defaultdict
def input(): return sys.stdin.readline().strip()

def main():
    n = int(input())
    D = [defaultdict(int) for _ in range(n)]
    for i in range(n):
        s = input()
        for c in s:
            D[i][c] += 1
    ans = ""
    for i in range(26):
        c = chr(i + 97)
        minimum = 10**18
        for d in D:
            if c not in d:
                minimum = 0
                break
            minimum = min(minimum, d[c])
        if minimum == 0: continue
        ans += c * minimum
    print(ans)
    

if __name__ == "__main__":
    main()
