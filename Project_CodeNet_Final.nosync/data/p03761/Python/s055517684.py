from collections import defaultdict
def solve():
    N = int(input())
    counters = []

    for i in range(N):
        counter = defaultdict(int)
        S = input()
        for ch in S:
            counter[ch] += 1

        counters.append(counter)
    
    ans = ""
    for ch_code in range(ord('a'), ord('z')+1):
        ch = chr(ch_code)
        mn = float('inf')
        for counter in counters:
            mn = min(mn, counter[ch])

        ans += ch * mn
    
    print(ans)
    
if __name__ == '__main__':
    solve()