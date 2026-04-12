import sys
input = sys.stdin.readline

def main():
    N = int(input())
    s = input().strip()

    next_o = {"SS": "S", "SW": "W","WS": "W", "WW": "S"}
    next_x = {"SS": "W", "SW": "S","WS": "S", "WW": "W"}

    for ans in ["SS", "SW", "WS", "WW"]:
        for i in range(1, N):
            if s[i] == "o":
                ans += next_o[ans[-2:]]
            else:
                ans += next_x[ans[-2:]]
        
        if ans[0] == ans[-1]:
            if s[0] == "o":
                if ans[1] == next_o[ans[-2:]]:
                    print(ans[:-1])
                    return
            else:
                if ans[1] == next_x[ans[-2:]]:
                    print(ans[:-1])
                    return
    
    print(-1)

if __name__ == "__main__":
    main()