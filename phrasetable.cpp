#include "pch.h"
#include "phrasetable.h"
#include<string.h>
using namespace std;

phrasetable::phrasetable()
{
	head = NULL;
}

void phrasetable::AddNode(char *str)
{
	if (str == NULL)return;
	if (head == NULL)
	{
		head = new phrase;
		strcpy(head->content, str);
		head->count = 1;
		head->next = NULL;
	}
	phrase *p = search(str);
	if (p == NULL)
	{
		phrase *r = head;
		while (r->next != NULL)r = r->next;
		r->next = new phrase;
		strcpy(r->next->content, str);
		r->next->count = 1;
		r->next->next = NULL;
	}
	else p->count++;
}
phrase *phrasetable::search(char *str)
{
	if (str == NULL)return NULL;
	phrase *p = head;
	while (p->next != NULL)
	{
		p = p->next;
		if (strcmp(p->content, str) == 0)
		return p;
	}
	return NULL;
}
phrasetable::~phrasetable()
{
	/*while (head != NULL)
	{
		phrase*r = head;
		head = head->next;
		delete r;
		r = NULL;
	}*/
}
bool phrasetable::empty()
{
	if (head !=NULL)return false;
	return true;
}
phrase*phrasetable::front()
{
	return head;
}
void phrasetable::pop()
{
	if (head = NULL)return;
	phrase *r = head;
	head = head->next;
	delete r;
	r = NULL;
}

void phrasetable::sort()
{
	/*phrase *h=NULL, *r = head;
	while (r != NULL)
	{
		phrase* p;
		if (h == NULL)
		{
			h = new phrase;
			strcpy(h->content, r->content);
		}
		r = r->next;
	}*/
}