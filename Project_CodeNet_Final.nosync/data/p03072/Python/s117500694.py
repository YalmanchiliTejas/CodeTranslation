
if __name__ == "__main__":
    n = int(input())
    h = list(map(int, input().split()))
    hlim = 0
    count = 0
    for hotel in h:
        if hotel >= hlim:
            hlim = hotel
            count += 1
        else:
            pass
    print(count)