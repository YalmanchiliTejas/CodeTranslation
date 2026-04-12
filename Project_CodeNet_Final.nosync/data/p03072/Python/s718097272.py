def main():
    n = int(input())
    h_n = [int(s) for s in input().split()]

    cnt = 0
    for i in range(0, n):
        diff = [h_n[i] - h_n[j] for j in range(0, i)]
        cnt = cnt + 1 if len(list(filter(lambda x: x < 0, diff))) == 0 else cnt

    print(cnt)

    
main()