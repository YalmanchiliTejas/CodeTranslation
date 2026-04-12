
def get_input():
    N = int(input())
    H = [int(_) for _ in input().split(" ")]
    return N,H

def solve(N,H):
    maximums = [max(H[:i+1]) for i in range(N)]
    count = 0
    for h,maximum in zip(H,maximums):
        if h>=maximum:
            count+=1
    return count 

if __name__ == "__main__":
    N,H = get_input()
    ans = solve(N,H)
    print(ans)