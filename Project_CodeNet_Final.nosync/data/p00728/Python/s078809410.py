if  __name__ == "__main__":
    while True:
        dataset = []
        n = 0
        n = int(input())
        if n== 0: break
        for i in range(n):
            dataset.append(int(input()))
        print(int(((sum(dataset) - min(dataset) - max(dataset))/(n - 2))))