def check_winner(N, M):
    if N == M:
        return "Yes"
    return "No"

if __name__ == "__main__":
    test1 = "3 3"
    test2 = "3 2"
    test3 = "5 0"
    test = test3
    test_input = map(int, input().split())
    print(check_winner(*test_input))
