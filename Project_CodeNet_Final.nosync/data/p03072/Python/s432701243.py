import sys

def main():
    input = sys.stdin.readline
    
    n = int(input())
    l = list(map(int, input().split()))
    
    view = 0
    
    for i in range(len(l)):
        if max(l[:i + 1]) <= l[i]:
            view = view + 1
            
    print(view)
    
if __name__ == '__main__':
    main()