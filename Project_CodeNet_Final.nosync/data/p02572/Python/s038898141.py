def resolve():
    import sys
    input = sys.stdin.readline
 
    n = input().rstrip()
    past_a = 0
 
    ans = 0
    for a in input().rstrip().split(" "):
        a = int(a)
        #print(a)
        ans += a * past_a
        #print(ans)
        past_a += a
        #print(past_a)
 
    x = 1000000007
 
    ans = ans % x
 
    print(ans)
 
if __name__ == "__main__":
    resolve()
