import sys

class alphabet: #Trueなら大文字
    def __init__(self, capitalize):
        self.num = dict()
        self.index = dict()
        self.abc = ["a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n"\
            ,"o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z"]
        if capitalize: 
            for i in range(26): self.abc[i] = self.abc[i].upper()
        for i, a in enumerate(self.abc):
            self.num[a] = i
            self.index[i] = a

def solve():
    input = sys.stdin.readline
    longest = 0
    AB = alphabet(False)
    ans = ""
    N = int(input())
    S = [input().strip("\n") for _ in range(N)]
    ABcount = [0] * 26
    for i in range(26):
        w = AB.index[i]
        M = 50
        for s in S:
            count = 0
            for j in range(len(s)):
                if s[j] == w: count += 1
            M = min(count, M)
        ABcount[i] = M
    Ans = ""
    for i, a in enumerate(ABcount): Ans += AB.index[i] * a
    print(Ans)
                          
    return 0

if __name__ == "__main__":
    solve()