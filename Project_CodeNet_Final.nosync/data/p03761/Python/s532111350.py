from collections import Counter

def main():
    n = int(input())
    s = Counter(input())
    for _ in range(n-1):
        s &= Counter(input())
    print("".join(sorted(s.elements())))
    
main()