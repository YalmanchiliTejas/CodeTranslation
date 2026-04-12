import sys
import decimal # 10進法に変換，正確な計算

def input():
    return sys.stdin.readline().strip()

def main():
    n, m = map(int, input().split())
    if n == m:
        print("Yes")
        return
    print("No")
    

main()