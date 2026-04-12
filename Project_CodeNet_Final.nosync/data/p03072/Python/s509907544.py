def main():
    input = sys.stdin.readline
    try:
        n = int(input())
        H = list(map(int, input().split()))
        
        cnt = 0
        now = 0
        for h in H:
            if h >= now:
                cnt += 1
            now = max(now,h)
            
        print(cnt)
        
    finally:
        input = None

import sys; sys.setrecursionlimit(50000)
if __name__ == "__main__":
    main()
