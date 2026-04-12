int main() {
	int a, b, c;
	__builtin_scanf("%d%d%d", &a, &b, &c);
	__builtin_printf("%d\n", (a - c) / (b + c));
	return 0;
}