def main():
    N = int(input())
    price = 800
    cashback_unit = 15
    cashbuck_rate = 200

    x = price*N
    y = cashbuck_rate*(N//cashback_unit)

    print(x - y)
main()