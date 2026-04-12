from bisect import bisect
def main():
    N,*A=map(int, open(0).read().split())
    B=[]
    for a in A:
        x=bisect(B,-a)
        if x>=len(B):
            B.append(-a)
        else:
            B[x]=-a
    print(len(B))

if __name__ == "__main__":
    main()