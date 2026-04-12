#include <bits/stdc++.h>

int main()
{
	int n, characters[26]{};
	std::fill(characters, characters + 26, 100);
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		std::string s;
		int tmp_table[26]{};
		std::cin >> s;
		for (auto &c: s)
			tmp_table[c - 'a']++;
		for (int i = 0; i < 26; i++)
			characters[i] = std::min(characters[i], tmp_table[i]);
	}
	for (int i = 0; i < 26; i++)
		for (int j = 0; j < characters[i]; j++)
			printf("%c", i + 'a');
	printf("\n");

	return 0;
}