#ifndef __VETERINARIO_H__
#define __VETERINARIO_H__

#include <funcionario.h>
#include <string>

/// Classe Veterionario
/**
 * O Veterionario é um Funcionario inscrito no Conselho Regional de Medicina Veterinária
 * sob um código de CRMV que deve estar vinculado aos animais para cuidados diários, caso
 * a espécie do animal esteja catalogada em uma das listas oficiais do IBAMA.
 * 
 * As espécies catalogadas em listas oficiais do IBAMA:
 *  - **Animais silvestres nativos**: mico, morcego, quati, onça, tamanduá, ema,
 *    papagaio, arara, canário-da-terra, tico-tico, galo-da-campina, teiú, etc.
 *  - **Animais silvestres exoticos**: leão, zebra, elefante, urso, *ferret*,
 *    lebre-européia, javali, crocodilo-do-Nilo, naja, tartaruga-de orelha-vermelha,
 *    cacatua, entre outros.
 *  - **Animais ameaçadas de extinção**: araraju, arara azul, ariranha, baleia-franco-do-sul,
 *    cervo-do-pantanal, gato-macarajá, lobo-guará, macaco-aranha, mico-leão-dourado,
 *    onça-pintada, tamanduá-bandeira, etc.
 */
class Veterinario : public Funcionario {
	public:
		/// Construtor de Veterinario sem parâmetros.
		/**
		*  Detailed description starts here.
		*/
		Veterinario();
		/// Destrutor de Veterinario.
		/**
		*  A more elaborate description of the destructor.
		*/
		~Veterinario();

	private:
		std::string m_crmv; ///< Código CRMV
};

#endif // __VETERINARIO_H__